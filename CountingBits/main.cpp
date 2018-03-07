#include <iostream>
#include "../myheader.h"

class Solution {
public:
    vector<int> countBits(int num) {
        auto ret = vector<int>(num + 1);
        ret[0] = 0;
        ret[1] = 1;
        int up = 4;
        int low = 2;
        for (int i = 2; i < num+1; i++) {
            if (i == up) {
                up *= 2;
                low *= 2;
            }
            ret[i] = 1 + ret[i - low];
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}