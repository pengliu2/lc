#include <iostream>
#include <vector>
#include "../treenode.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return ans.first;
    }
private:
    pair<int, int> helper(TreeNode* node) {
        if (node == nullptr) return make_pair(0, 0);
        pair<int, int> left = helper(node->left);
        pair<int, int> right = helper(node->right);
        int d = max(left.second, right.second) + 1;
        int ans = max(max(left.first, right.first), left.second + right.second);
        return make_pair(ans, d);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}