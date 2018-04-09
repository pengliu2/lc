#include <iostream>
#include <algorithm>

#include "../treenode.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int ret = 1;
        if (root->left != nullptr)
            ret = dfs(root->left) + 1;
        if (root->right != nullptr)
            ret = max(ret, dfs(root->right) + 1);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}