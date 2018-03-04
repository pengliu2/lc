#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (((maxChoosableInteger + 1) * maxChoosableInteger / 2) < desiredTotal)
            return false;

        unordered_map<int, int> cache;
        int sign = (1L << maxChoosableInteger) - 1;
        bool ret = dfs_win(cache, sign, maxChoosableInteger, desiredTotal);
        cout << cache[sign] << endl;
        return ret;
    }

    bool dfs_win(unordered_map<int, int> &cache, int sign, int maxC, int target) {
        if (cache.count(sign) != 0){
            return cache[sign] > 0;
        }

        int ret = 0;
        int total = 0;
        for (int i = maxC; i > 0; i--) {
            if ((sign & (1L << (i - 1))) == 0) continue;
            total += 1;
            if (i >= target) {
                cache[sign] = i;
                return true;
            }
            int s = sign ^ (1L << (i - 1));
            bool r = dfs_lose(cache, s, maxC, target - i);
            if (r) {
                cache[sign] = i;
                return true;
            }
            if (cache[s] > 0) {
                ret += 1;
            }
        }
        if (ret == total) {
            cache[sign] = -1;
        }
        return false;
    }

    bool dfs_lose(unordered_map<int, int> &cache, int sign, int maxC, int target) {
        if (cache.count(sign) != 0) {
            return cache[sign] < 0;
        }

        int total = 0;
        int ret = 0;
        for (int i = maxC; i > 0; i--) {
            if ((sign & (1L << (i - 1))) == 0) continue;
            if (i >= target) {
                cache[sign] = i;
                return false;
            }
            int s = sign ^ (1L << (i-1));
            total += 1;
            bool r = dfs_win(cache, s, maxC, target - i);

            if (!r && (cache[s] < 0)) {
                cache[sign] = i;
                return false;
            }

            if (r)
                ret+=1;
        }
        if (ret == total) {
            cache[sign] = -1;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}