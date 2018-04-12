#include <iostream>
#include <algorithm>
#include "../treenode.h"

using namespace std;

/*
 * reminder:
 * 1. SolutionI: TLE: repeating dfs(node, false)
 *
 */

class Solution {
public:
    int rob(TreeNode* root) {
        int rob;
        int nop;
        dfs(root, &rob, &nop);
        return max(rob, nop);
    }

    void dfs(TreeNode *node, int *rob, int *nop) {
        *rob = 0;
        *nop = 0;
        if (node == nullptr) return;

        int left_r;
        int left_n;
        int right_r;
        int right_n;

        dfs(node->left, &left_r, &left_n);
        dfs(node->right, &right_r, &right_n);

        *rob = node->val + left_n + right_n;
        *nop = max(left_r, left_n) + max(right_r, right_n);
    }
};


class SolutionI {
public:
    int rob(TreeNode* root) {
        return max(dfs(root, true), dfs(root, false));
    }

    int dfs(TreeNode *node, bool rob) {
        int ret = 0;
        if (node == nullptr) return ret;

        int left = dfs(node->left, false);
        int right = dfs(node->right, false);
        if (rob) {
            ret += node->val;
            return ret + left + right;
        }

        left = max(left, dfs(node->left, true));
        right = max(right, dfs(node->right, true));
        return left + right;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}