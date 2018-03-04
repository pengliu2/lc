#include <iostream>
#include "../myheader.h"


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) return true;

        vector<vector<int>> m(maxChoosableInteger, vector<int>(0));

        long max_sign = (1UL << maxChoosableInteger) - 1;
        m[0] = vector<int>(max_sign + 1, 0);
        for (long sign = 0; sign <= max_sign; sign++) {
            m[0][sign] = -1;
        }
        m[1] = vector<int>(max_sign + 1, maxChoosableInteger+1);
        m[1][0] = 0;

        for (int i = 2; i <= desiredTotal; i++) {
            construct_next(m, i, maxChoosableInteger, max_sign);
        }

        return m[desiredTotal%maxChoosableInteger][(1<<maxChoosableInteger)-1] > 0;
    }

    // given a target and left choosable integers
    // when there is an integer, with which being taken off, other person must lose, then integer+sign marked 1
    // when with any integer, other person must win, then integer+sign marked -1
    // otherwise, marked 0
    void construct_next(vector<vector<int>> &m, int target, int maxC, int max_sign) {
        int slot = target % maxC;
        vector<int> newrule(max_sign + 1, maxC+1);

        for (unsigned long sign = 1; sign <= max_sign; sign++) {
            if ((sign >= (1UL << (target-1)))) {
                newrule[sign] = maxC+1;
                break;
            }
            bool must_lose = true;
            for (int takeoff = 1; takeoff <= min(maxC, target-1); takeoff++) {
                if ((1UL << (takeoff-1)) > sign)
                    break;
                if ((sign & (1UL<<(takeoff-1))) == 0 )
                    continue;
                int nsign = sign ^ (1UL<<(takeoff-1));
                int s = (target - takeoff + maxC) % maxC;
                if (m[s].size() == 0) {
                    continue;
                }
                if (m[s][nsign] == 0) {
                    newrule[sign] = 0;
                    must_lose = false;
                    break;
                }
                if (m[s][nsign] == -1) {
                    newrule[sign] = takeoff;
                    must_lose = false;
                    break;
                }
            }
            if (must_lose) {
                newrule[sign] = -1;
            }
        }
        m[slot] = newrule;
    }
};

int main() {
    Solution slt;
    bool ret = slt.canIWin(20, 209);
    if (ret)
        cout << "win" << endl;
    else
        cout << "no win" << endl;
    char a;
    cin >> a;
    return 0;
}


