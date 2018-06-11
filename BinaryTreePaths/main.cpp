#include <iostream>
#include <vector>
#include "../treenode.h"

/*
 * reminders:
 * 1. "1->2->3" don't forget check if it's the first element so we don't have to give it "->"
 */

using namespace std;


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans;
        string cur;
        helper(root, ans, cur);
        return ans;
    }
private:
    void helper(TreeNode* node, vector<string>& ans, string& cur) {
        size_t size = cur.size();
        if (cur.size() != 0) cur += "->";
        cur += (to_string(node->val));
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(string(cur));
        } else {
            if (node->left != nullptr) {
                helper(node->left, ans, cur);
            }
            if (node->right != nullptr) {
                helper(node->right, ans, cur);
            }
        }
        cur.resize(size);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}