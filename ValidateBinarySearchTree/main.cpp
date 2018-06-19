#include <iostream>
#include "../treenode.h"


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int small;
        int large;
        if (root == nullptr) return true;
        return helper(root, &small, &large);
    }

private:
    bool helper(TreeNode* node, int* small, int* large) {
        *small = node->val;
        *large = node->val;
        if (node->left != nullptr) {
            int left_small;
            int left_large;
            bool ret = helper(node->left, &left_small, &left_large);
            if (!ret) return false;
            if (left_large >= node->val) return false;
            *small = left_small;
        }
        if (node->right != nullptr) {
            int right_small;
            int right_large;
            bool ret = helper(node->right, &right_small, &right_large);
            if (!ret) return false;
            if (right_small <= node->val) return false;
            *large = right_large;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}