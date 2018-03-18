#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. j <= dist instead of j < dist to visit the item itself
 */

class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        int size = s.length();
        for (int i = 0; i < size; i++) {
            int dist = min(i, size-1-i);
            for (int j = 0; j <= dist; j++) {
                if (s[i+j] == s[i-j]) {
                    ret++;
                } else {
                    break;
                }
            }
            dist = min(i, size-2-i);
            if (dist < 0) continue;
            for (int j = 0; j <= dist; j++) {
                if (s[i+j+1] == s[i-j]) {
                    ret++;
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}