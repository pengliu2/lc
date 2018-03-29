#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. vector::back() has different meaning
 * */

class Solution_for_II {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int keep = INT_MIN;
        int finish = 0;
        for (int i = 0; i < prices.size(); i++) {
            int prev_finish = finish;
            finish = max(finish, keep + prices[i]);
            keep = max(keep, prev_finish - prices[i]);
        }
        return finish;
    }
};

class SolutionII {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        bool has = false;
        int cost = prices[0];
        int profit = 0;
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (!has) {
                if (prices[i] <= cost) {
                    cost = prices[i];
                } else {
                    has = true;
                    profit = prices[i] - cost;
                }
            } else {
                if (prices[i] - cost < profit) {
                    ret += profit;
                    has = false;
                    cost = prices[i];
                } else {
                    profit = prices[i] - cost;
                }
            }
        }
        if (has && prices[prices.back()] > cost)
            ret += prices[prices.back()] - cost;
        return ret;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        int lowest = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowest)
                lowest = prices[i];
            else {
                profit = max(profit, prices[i] - lowest);
            }
        }
        return profit;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}