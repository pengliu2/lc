#include <iostream>
#include "../treenode.h"
#include <string>

using namespace std;

/*
 * reminders:
 * 1. values might be negative
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        _s(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len;
        return _d(data, 0, &len);

    }

private:
    void _s(TreeNode* node, string& s) {
        if (!s.empty()) {
            s.push_back(',');
        }
        if (node == nullptr) {
            s.push_back('N');
            return;
        }
        s += to_string(node->val);

        _s(node->left, s);
        _s(node->right, s);
    }

    TreeNode* _d(string& s, int index, int* next) {
        if (index >= s.size()) return nullptr;
        if (s[index] == 'N') {
            *next = index + 2;
            return nullptr;
        }
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
            index += 1;
        }
        int val = 0;
        int i = index;
        for (; i < s.size(); i++) {
            if (s[i] == ',') {
                break;
            }
            val = val*10 + (s[i] - '0');
        }

        TreeNode* ans = new TreeNode(val*sign);
        int n;
        TreeNode* left = _d(s, i+1, &n);
        TreeNode* right = _d(s, n, &n);

        *next = n;
        ans->left = left;
        ans->right = right;
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}