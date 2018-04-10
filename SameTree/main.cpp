#include <iostream>
#include "../treenode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == nullptr || q == nullptr)
            if( p != q)
                return false;
            else
                return true;
        if (p->val != q->val) return false;
        if (!dfs(p->left, q->left)) return false;
        if (!dfs(p->right, q->right)) return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}