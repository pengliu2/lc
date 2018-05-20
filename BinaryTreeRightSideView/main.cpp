#include <iostream>
#include "../treenode.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        helper(ret, 1, root);
        return ret;
    }

    void helper(vector<int> &ret, int level, TreeNode* root) {
        if (root == nullptr) return;
        if (ret.size() < level) {
            ret.push_back(root->val);
        } else {
            ret[level - 1] = root->val;
        }

        helper(ret, level+1, root->left);
        helper(ret, level+1, root->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}