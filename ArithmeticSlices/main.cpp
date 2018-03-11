#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        auto size = A.size();
        if (size < 3) return 0;

        int total = 0;
        auto cache = vector<bool>(size, false);
        for (int i = 0; i < size - 2; i++) {
            if (A[i+2] - A[i+1] == A[i+1] - A[i]) {
                cache[i] = true;
                total += 1;
            }
        }

        for (int i = 4; i <= size; i++) {
            for (int j = 0; j <= size - i; j++) {
                if (cache[j] && cache[j+1]) {
                    total += 1;
                } else {
                    cache[j] = false;
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