#include <iostream>
#include <queue>
#include "../treenode.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            q.push_back(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* ans = q.back();
        q.pop_back();

        if (ans->right != nullptr) {
            TreeNode* nod = ans->right;
            while(nod != nullptr) {
                q.push_back(nod);
                nod = nod->left;
            }
        }
        return ans->val;
    }
private:
    deque<TreeNode*> q;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}