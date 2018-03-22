#include <iostream>
#include "../myheader.h"

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}