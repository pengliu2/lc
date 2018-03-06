#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;

        int size = s1.size();
        auto cache = unordered_map<string, unordered_map<string, bool>>();

        return dfs(cache, s1, 0, size - 1, s2, 0, size -1, size);
    }

    bool dfs(unordered_map<string, unordered_map<string, bool>> &cache, string &s1, int b1, int e1, string &s2, int b2, int e2, int size) {
        if (b1 == e1) {
            if (s1[b1] == s2[b2])
                return true;
            else
                return false;
        }
        if (s1.compare(b1, e1-b1+1, s2, b2, e2-b2+1) == 0) return true;

        if (b1 + 1 == e1) {
            if ((s1[b1] == s2[e2]) && (s1[e1] == s2[b2]))
                return true;
            else
                return false;
        }

        int len = e1 - b1;
        string sub1 = s1.substr(b1, len);
        string sub2 = s2.substr(b2, len);
        if (cache.count(sub1) != 0) {
            if (cache.count(sub2) != 0) {
                return cache[sub1][sub2];
            }
        }

        for (int i = 0; i < e1-b1; i++) {
            if (dfs(cache, s1, b1, b1 + i, s2, b2, b2 + i, size)
                && dfs(cache, s1, b1 + i + 1, e1, s2, b2 + i + 1, e2, size)) {
                cache[sub1][sub2] = true;
                return true;
            }
            if (dfs(cache, s1, b1, b1+i, s2, b2 + len - i, e2, size)
                    && dfs(cache, s1, b1+len-i, e1, s2, b2+i, e2, size)) {
                cache[sub1][sub2] = true;
                return true;
            }
        }
        cache[sub1][sub2] = false;
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}