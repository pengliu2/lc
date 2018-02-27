#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sign = (1UL << maxChoosableInteger) - 1;
        return check(desiredTotal, sign, maxChoosableInteger);
    }

    map<int, bool> cache{};

    bool check(int desired, int sign, int maxNumber) {
        int index = (desired << 20) | sign;
        if (cache.count(index) != 0) {
            return cache[index];
        }

        bool ret = true;
        for (int i = 1; i <= maxNumber; i++) {
            if ((sign & (1 << (i-1))) == 0)
                continue;
            if (i >= desired) {
                cache.emplace(index, true);
                return true;
            }
            int new_desired = desired - i;
            int new_sign = sign ^ (1UL << (i-1));
            if (check(new_desired, new_sign, maxNumber) == false) {
                ret = false;
            }
        }

        cache.emplace(index, true);
        return true;
    }
};

int main() {
    Solution slt;
    bool ret = slt.canIWin(10, 40);
    if (ret)
        cout << "win" << endl;
    else
        cout << "no win" << endl;
    char a;
    cin >> a;
    return 0;
}


