#include <iostream>
#include "../myheader.h"

class Solution {
public:
    vector<int> countBits(int num) {
        auto ret = vector<int>(num + 1);
        for (int i = 0; i < num+1; i++) {
            int n = i;
            int t = 0;
            while (n > 0) {
                if ((n & 0x01UL) != 0) t++;
                n = n >> 1;
            }
            ret[i] = t;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}