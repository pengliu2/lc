#include <iostream>
#include <vector>
#include <climits>

/* reminder
 * 1. must update 2buy2sell before 2buy 1sell
 * 2. k might be huge and actually we can only do size()/2 transactions
 * 3. size()/2 isn't int
 * 4. half transaction and full transaction all initialized to INT_MIN
 * 5. create one single array for all cached data is better than separating half and full
 * */

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (k <= 0) return 0;

        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }

        k = min(k, static_cast<int>(prices.size())/2);
        auto cache = vector<int>(k*2 + 1, INT_MIN);

        cache[0] = 0;
        cache[1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            for (int j = min(k * 2, i+1); j >= 1; j--) {
                if (j % 2 == 1) {
                    cache[j] = max(cache[j], cache[j-1] - prices[i]);
                } else {
                    cache[j] = max(cache[j], cache[j-1] + prices[i]);
                }
            }
        }

        return cache[k*2];
        int ret = 0;
        for (int i = 0; i < k * 2 + 1; i += 2) {
            ret = max(ret, cache[i]);
        }
        return ret;
    }
};

class SolutionOthers {
public:
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i=0; i<len; ++i){
            cur = prices[i];
            for(int j=k; j>0; --j){
                rele[j] = max(rele[j],hold[j] + cur);
                hold[j] = max(hold[j],rele[j-1] - cur);
            }
        }
        return rele[k];
    }
};

class SolutionII {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (k <= 0) return 0;

        auto half = vector<int>(k+2, INT_MAX);
        auto full = vector<int>(k+1, INT_MIN);
        full[0] = 0;
        half[1] = -prices[0];
        for (int i = 0; i < prices.size(); i++) {
                for (int m = min(k, (i+1)/2); m >= 1; m-- ) {
                    half[m] = min(half[m], full[m-1] - prices[i]);
                    full[m] = max(full[m], half[m] + prices[i]);
                }
        }

        int ret = 0;
        for (int i = 0; i < k+1; i++) {
            ret = max(ret, full[i]);
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

