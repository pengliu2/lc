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
        int dout = 0;
        return  dfs(root, &dout);
    }

    int dfs(TreeNode *root, int *dout) {
        int ret = root->val;
        *dout = 1;
        if (root->left != nullptr) {
            int d;
            ret  =  dfs(root->left, &d);
            *dout = d+1;
        }
        if (root->right != nullptr) {
            int d;
            int ret1 = dfs(root->right, &d);
            if (*dout < d+1) {
                ret = ret1;
                *dout = d+1;
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}