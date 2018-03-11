#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int size = p.length();
        if (size == 0) return 0;

        vector<int> maxlen = vector<int>(26, 0);
        maxlen[p[0]-'a'] = 1;
        int start = 0;
        int len = 1;
        for (int i = 1; i < size; i++) {
            if (p[i] % 26 == (p[i-1] + 1) % 26) {
                len++;
            } else {
                for (int j = 0; j < 26; j++) {
                    maxlen[p[start + j] - 'a'] = max(maxlen[p[start + j] - 'a'], len);
                    len--;
                    if (len == 0) break;
                }
                len = 1;
                start = i;
            }
        }
        for (int j = 0; j < 26; j++) {
            maxlen[p[start + j] - 'a'] = max(maxlen[p[start + j] - 'a'], len);
            len--;
            if (len == 0) break;
        }
        int total = 0;
        for (int i = 0; i < 26; i++) {
            total += maxlen[i];
        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}