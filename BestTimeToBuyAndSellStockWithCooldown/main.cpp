#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. Solution II is wrong
 * because we cannot decide that we shouldn't sell at i-2 or i-3 just because i > i-2. For example 1, 2, 3, 8, 7, 9, 7, 10
 * we still need to sell at 8, so that we can buy at second 7
 *
 * 2. stead we need to reuse the concept of this solution for BuyAndSellStock I:
 * if (p[i]-p[i-1] > 0) ret+=(p[i]-p[i-1]);
 * because actually we can buy yesterday's stock we can have all the profit and avoid loss.
 *
 * the difference is at day i, we might
 *  - have sold before i-2: then we have profit of p[i]-p[i-1] if any
 *  - at i-2              : then we don't have profit of [i]-p[i-1]
 *  - still keep stock    : we can have gain of p[i]-p[i-1] if any but might not be highest
 * we have to look back even further than yesterday to achieve max profit
 *
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int sold_before = 0;
        int just_cooled = 0;
        int still_have = max(0, prices[1]-prices[0]);
        for (int i = 2; i < prices.size(); i++) {
            int prev_sold = sold_before;
            sold_before = max(just_cooled, sold_before);
            just_cooled = still_have;
            still_have = max(still_have + prices[i] - prices[i-1], prev_sold + max(0, prices[i] - prices[i-1]));

        }
        return max(max(still_have, just_cooled), sold_before);
    }
};


class SolutionII {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int lowest = prices[0];
        int i = 0;
        int ret = 0;
        auto cache = vector<int>(prices.size()+2, 0);
        while (i < prices.size()) {
            while (i < prices.size() && prices[i] <= lowest ) {
                cache[i] = prices[i];
                if (prices[i] < lowest)
                    lowest = i;
                i++;
            }
            if (i >= prices.size())
                break;
            while (i < prices.size() && prices[i] >= cache[i-1]) {
                if (prices[i] > cache[i-1])
                    cache[i] = prices[i];
                else
                    cache[i] = cache[i-1];
                i++;
            }
            i++;
            if (i >= prices.size()) {
                ret += cache[i-1] - lowest;
                break;
            }
            if (cache[i-3] > min(prices[i], prices[i-1]) && cache[i-3] - min(prices[i], prices[i-1]) > cache[i-2] - prices[i]) {
                ret += cache[i-3] - lowest;
                lowest = prices[--i];
            } else if (prices[i] < cache[i-2]) {
                ret += cache[i] - lowest;
                lowest = prices[i];
            };
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}