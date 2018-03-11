#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int size = p.length();
        if (size == 0) return 0;

        int total = 0;
        unsigned int scache = 0;
        auto cache = set<int>();
        for (int i = 0;  i < size; i++) {
            if (((scache >> (p[i] - 'a')) & 0x01UL) != 0) continue;
            scache = scache | (0x01UL << (p[i] - 'a'));
            total++;
        }
        scache = 0;
        for (int j = 0; j < size -1; j++) {
            if (((scache >> (p[j] - 'a')) & 0x01UL) != 0) {
                cache.insert(j);
                continue;
            }
            if ((p[j] - 'a' + 1)%26 == (p[j+1]-'a')%26) {
                total++;
                scache = scache | (0x01UL << (p[j] - 'a'));
                cache.insert(j);
            }
        }

        for (int i = 3; i <= size; i++) {
            scache = 0;
            if (cache.empty()) break;
            for (set<int>::iterator it = cache.begin(); it != cache.end();) {
                if (((scache >> (p[*it] - 'a')) & 0x01UL) != 0) {
                    it++;
                    continue;
                }
                if ((p[*it+i-2] - 'a' + 1)%26 == (p[*it+i-1]-'a')%26) {
                    total++;
                    scache = scache | (0x01UL << (p[*it] - 'a'));
                    it++;
                } else {
                    it=cache.erase(it);
                }
            }

        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}