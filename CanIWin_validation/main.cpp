#include <iostream>
#include <iostream>
#include "../myheader.h"


class Solution {
public:
    vector<vector<int>> canIWin(int maxChoosableInteger, int desiredTotal) {
        //if (desiredTotal <= maxChoosableInteger) return true;

        vector<vector<int>> m(maxChoosableInteger, vector<int>(0));

        long max_sign = (1UL << maxChoosableInteger) - 1;
        m[0] = vector<int>(max_sign + 1, 0);
        for (long sign = 0; sign <= max_sign; sign++) {
            m[0][sign] = -1;
        }
        m[1] = vector<int>(max_sign + 1, 1);
        m[1][0] = 0;

        for (int i = 2; i <= desiredTotal; i++) {
            construct_next(m, i, maxChoosableInteger, max_sign);
        }

        return m;
    }

    // given a target and left choosable integers
    // when there is an integer, with which being taken off, other person must lose, then integer+sign marked 1
    // when with any integer, other person must win, then integer+sign marked -1
    // otherwise, marked 0
    void construct_next(vector<vector<int>> &m, int target, int maxC, int max_sign) {
        int slot = target % maxC;
        vector<int> newrule(max_sign + 1, 0);

        for (long sign = 1; sign <= max_sign; sign++) {
            if ((sign >> (target -1)) >= 1) {
                newrule[sign] = 1;
                continue;
            }
            bool must_lose = true;
            for (int takeoff = 1; takeoff <= min(maxC, target); takeoff++) {
                if (sign & (1<<(takeoff-1))==0)
                    continue;
                int nsign = sign ^ (1<<(takeoff-1));
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
                if (m[s][nsign] != 1) {
                    must_lose = false;
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
    auto m = slt.canIWin(10, 32);
    long sign = 0x3BF;

    for (int i = 10; i > 0; i--) {
        int newvalue = 33 - i;
        long newsign = sign ^ (1UL << (i-1));
        cout << newvalue << "+" << newsign << ": first take off " << m[newvalue%10][newsign] << endl;
    }

    char a;
    cin >> a;

    return 0;
}


