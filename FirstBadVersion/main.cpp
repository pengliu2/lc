#include <iostream>

/*
 * reminder:
 * 1. binary search: if high has a known state, low = mid + 1 to keep low's state unknown
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (high > low) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}