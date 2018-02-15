#include <iostream>
#include <vector>

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

class Solution {
public:
    void con(TreeLinkNode *n, std::vector<TreeLinkNode*>& left, std::vector<TreeLinkNode*>& right) {
        n->next = nullptr;
        left.push_back(n);
        right.push_back(n);
        if (n->left != nullptr) {
            std::vector<TreeLinkNode *> ll;
            std::vector<TreeLinkNode *> lr;
            std::vector<TreeLinkNode *> rl;
            std::vector<TreeLinkNode *> rr;
            con(n->left, ll, lr);
            con(n->right, rl, rr);
            auto i = ll.size();
            for (auto j = 0; j < i; j++) {
                lr[j]->next = rl[j];
                rr[j]->next = nullptr;
                left.push_back(ll[j]);
                right.push_back(rr[j]);
            }
        }
        return;
    }


    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        std::vector<TreeLinkNode*> l;
        std::vector<TreeLinkNode*> r;
        con(root, l, r);
    }
};

int main() {
    return 0;
}