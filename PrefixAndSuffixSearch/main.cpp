#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

struct MyTrieNode {
    set<int> indices;
    vector<MyTrieNode*> letters;
    MyTrieNode() {indices = set<int>(); letters = vector<MyTrieNode*>(26, nullptr);}
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        front = new MyTrieNode();
        rear = new MyTrieNode();
        e = set<int>();
        for (int i = 0; i < words.size(); ++i) {
            insert_front(front, words[i], i);
            insert_rear(rear, words[i], i);
        }
    }

    int f(string prefix, string suffix) {
        set<int> f = find_front(front, prefix);
        if (f.empty()) return -1;
        set<int> r = find_rear(rear, suffix);
        if (r.empty()) return -1;
        for (auto it = f.rbegin(); it != f.rend(); ++it) {
            if (r.find(*it) != r.end()) return *it;
        }
        return -1;
    }
private:
    set<int> e;
    MyTrieNode* front;
    MyTrieNode* rear;

    set<int>& find_front(MyTrieNode* n, const string& prefix) {
        for (int i = 0; i < prefix.size(); ++i) {
            if (n->letters[prefix[i]-'a'] == nullptr) return e;
            n = n->letters[prefix[i]-'a'];
        }
        return n->indices;
    }

    set<int>& find_rear(MyTrieNode* n, const string& suffix) {
        for (int i = suffix.size()-1; i >= 0; --i) {
            if (n->letters[suffix[i]-'a'] == nullptr) return e;
            n = n->letters[suffix[i]-'a'];
        }
        return n->indices;
    }


    void insert_front(MyTrieNode* n, const string& s, int w) {
        for (int i = 0; i < s.size(); ++i) {
            n->indices.insert(w);
            if (n->letters[s[i] - 'a'] == nullptr) {
                n->letters[s[i] - 'a'] = new MyTrieNode();
            }
            n = n->letters[s[i]-'a'];

        }
        n->indices.insert(w);
    }

    void insert_rear(MyTrieNode* n, const string& s, int w) {
        for (int i = s.size()-1; i >=0; --i) {
            n->indices.insert(w);
            if (n->letters[s[i] - 'a'] == nullptr) {
                n->letters[s[i] - 'a'] = new MyTrieNode();
            }
            n = n->letters[s[i]-'a'];

        }
        n->indices.insert(w);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}