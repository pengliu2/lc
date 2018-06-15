#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * reminders:
 * 1. recursive: remember to examine termination condition
 * 2. trie for word search: there must be a special mark for word end
 */

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        add_helper(&root, word, 0);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(root, word, 0);
    }

    ~WordDictionary() {
        dest_helper(root);
    }
    struct TreeNode {
        vector<TreeNode*> children;
        TreeNode() {children = vector<TreeNode*>(27, nullptr);}
    };
private:
    TreeNode* root;

    void add_helper(TreeNode** node, string& word, int index) {
        if (index == word.size()){
            (*node)->children[26] = new TreeNode();
            return;
        }
        if ((*node)->children[word[index]-'a'] == nullptr)
            (*node)->children[word[index]-'a'] = new TreeNode();
        add_helper(&((*node)->children[word[index] - 'a']), word, index+1);
    }

    bool search_helper(TreeNode* node, string& word, int index) {
        if (index == word.size()) {
            if (node->children.back() != nullptr)
                return true;
            else
                return false;
        }

        if (word[index] == '.') {
            for (const auto v : node->children) {
                if (v != nullptr)
                    if (search_helper(v, word, index+1)) return true;
            }
            return false;
        } else {
            if (node->children[word[index] - 'a'] == nullptr)
                return false;
            return (search_helper(node->children[word[index]-'a'], word, index+1));
        }
    }

    void dest_helper(TreeNode* node) {
        if (node == nullptr) return;
        for (auto v : node->children) {
            dest_helper(v);
        }
        delete node;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}