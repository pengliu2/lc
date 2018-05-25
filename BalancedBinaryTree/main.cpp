#include <iostream>
#include "../treenode.h"
#include <cmath>

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int ret = helper(root);
        return ret >= 0;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        if (left < 0 || right < 0) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}