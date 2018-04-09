#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> ret = dfs(root, 0);
        return ret[0];
    }

    vector<int> dfs(TreeNode *root, int depth) {
        vector<int> ret = vector<int>{root->val, depth};
        if (root->left != nullptr) {
            ret =  dfs(root->left, depth+1);
        }
        if (root->right != nullptr) {
            vector<int> ret1 = dfs(root->right, depth+1);
            if (ret1[1] > ret[1]) {
                ret[0] = ret1[0];
                ret[1] = ret1[1];
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}