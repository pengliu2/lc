#include <iostream>
#include "../myheader.h"

/* reminder:
 * 0. this question is actually a math problem: to prove the least number of steps are sum of primes
 * this one is actually like the palinmic problem if restrictly using dp
 * 1. first attempt: TLE at 5
 * It seems I still need to do multiple step caching.
 * 2. I firstly think I can do i*2 only so loop was from 1 to n/2+1
 * But later on I changed mind to inlucde i+cache[i] but I forgot to update the loop
 * */
class Solution {
public:
    int minSteps(int n) {
        if (n==1) return 0;
        int r = n;
        vector<int> ret;
        while (r != 1) {
            int i = 2;
            for (; i*i < r; i++) {
                if (r % i == 0) {
                    ret.push_back(i);
                    r = r/i;
                    break;
                }
            }
            if (i*i == r) {
                ret.push_back(i);
                ret.push_back(i);
                break;
            }
            if (i*i > r) {
                ret.push_back(r);
                break;
            }
        }
        return accumulate(ret.begin(), ret.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}