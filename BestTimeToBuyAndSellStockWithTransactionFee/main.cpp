#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. SolutionII is clearer: local minimum and local maximum
 * 2. SolutionII is more like a common solution for all stock problems:
 *    - first inner loop: tries to find a bottom line sell point while keep updating cost to lowest
 *    - second inner loop: tries to find the real sell point while keep updating profit to high
 * 3. when bottom line sell point cannot be found, break after first inner loop.
 *
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int low = -1;
        int high = -1;
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (low < 0) {
                low = i;
                high = i;
            } else if ((prices[i] < prices[high]) && (prices[high] > prices[low] + fee) && (prices[high] > prices[i] + fee) ) {
                ret += prices[high] - prices[low] - fee;
                low = i;
                high = i;
            } else if (prices[i] < prices[low]) {
                low = i;
                high = i;
            } else if (prices[i] > prices[high]) {
                high = i;
            }
        }
        if (prices[high] > prices[low] + fee)
            ret += prices[high] - prices[low] - fee;
        return ret;
    }
};

class SolutionII {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() < 2) return 0;

        int ret = 0;
        int i = 0;

        int lowest;
        int highest = 0;

        while (i < prices.size()) {
            lowest = prices[i];
            while (i < prices.size() && prices[i] <= lowest + fee) {
                if (prices[i] < lowest)
                    lowest = prices[i];
                i++;
            }
            if (i < prices.size())
                highest = prices[i];
            else
                break;
            while (i < prices.size() && prices[i] >= highest - fee) {
                if (prices[i] > highest)
                    highest = prices[i];
                i++;
            }
            ret += highest - lowest - fee;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}