#include <iostream>
#include "../treenode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr && right != nullptr) return false;
        if (left != nullptr && right == nullptr) return false;
        if (left->val != right->val) return false;

        if (!helper(left->left, right->right)) return false;
        if (!helper(left->right, right->left)) return false;

        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}