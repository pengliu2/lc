#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int size = p.length();
        if (size == 0) return 0;

        int total = 0;

        auto cache = vector<bool>(size, true);
        for (int i = 1; i <= size; i++) {
            unsigned int scache = 0;
            for (int j = 0; j <= size - i; j++) {
                if (i == 1) {
                    cache[j] = true;
                }
                else if (cache[j] && ((p[j+i-2] - 'a' + 1)%26 == (p[j+i-1]-'a')%26)) {
                    cache[j] = true;
                    //cout << p.substr(j,i) << ":" << j << endl;
                } else {
                    cache[j] = false;
                }
                if (!cache[j]) continue;
                if (((scache >> (p[j] - 'a')) & 0x01UL) != 0) continue;
                scache = scache | (0x01UL << (p[j] - 'a'));
                total++;
            }
        }
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}