#include <iostream>
#include <stack>
#include <vector>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void dfs(TreeLinkNode *n, std::vector<TreeLinkNode*>& s, int level) {
        if (n == nullptr)
            return;

        if (s.size() > level) {
            if (s[level] != nullptr) {
                s[level]->next = n;
            }
            s[level] = n;
        } else {
            s.push_back(n);
        }

        if (n->left != nullptr) {
            dfs(n->left, s, level + 1);
        }

        if (n->right != nullptr) {
            dfs(n->right, s, level + 1);
        }
    }
    void connect(TreeLinkNode *root) {
        std::vector<TreeLinkNode*> s;
        dfs(root, s, 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}