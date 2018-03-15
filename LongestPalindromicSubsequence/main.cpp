#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        if (size == 0) return 0;

        vector<int> cache(size, 0);
        int pos[26]{-1};
        cache[0] = 1;
        for (int i = 1; i < size; i++) {
            int prev = cache[i];
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == s[i]) {
                    int temp = prev;
                    prev = cache[j];
                    cache[j] = max(cache[j], temp+2);
                } else {
                    prev = cache[j];
                    cache[j] = max(cache[j], cache[j+1]);
                }
            }
            cache[i] = 1;
        }
        return cache[0];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
