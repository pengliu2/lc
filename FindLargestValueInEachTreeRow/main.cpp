#include <iostream>
#include <vector>
#include "../treenode.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        largest = vector<int>();
        if (root == nullptr) return largest;
        dfs(root, 0);
        return largest;
    }

    void dfs(TreeNode *root, int depth) {
        if (largest.size() > depth) {
            if (root->val > largest[depth])
                largest[depth] = root->val;
        }
        else
            largest.push_back(root->val);

        if (root->left) {
            dfs(root->left, depth+1);
        }
        if (root->right) {
            dfs(root->right, depth+1);
        }
    }
private:
    vector<int> largest;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}