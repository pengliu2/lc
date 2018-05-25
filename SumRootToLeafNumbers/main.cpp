#include <iostream>
#include "../treenode.h"

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

private:
    int helper(TreeNode* node, int sofar) {
        if (node == nullptr) return 0;
        sofar *= 10;
        sofar += node->val;
        if (node->right == nullptr && node->left == nullptr) return sofar;
        int ret = helper(node->left, sofar);
        ret += helper(node->right, sofar);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}