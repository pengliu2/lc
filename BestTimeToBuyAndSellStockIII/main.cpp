#include <iostream>
#include "../myheader.h"

/* reminder
 * 1. don't forget to check if first and last element is iterated
  */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        if (prices.size() == 2) return max(0, prices[1] - prices[0]);

        auto larger = vector<int>(prices.size(), 0);
        auto smaller = vector<int>(prices.size(), 0);
        auto single = vector<int>(prices.size(), 0);
        auto smallest = vector<int>(prices.size(), 0);
        larger[1] = max(0, prices[1]-prices[0]);
        single[1] = larger[1];
        smallest[1] = min(prices[0], prices[1]);

        for (int i = 2; i < prices.size(); i++) {
            larger[i] = larger[i-1];
            smaller[i] = smaller[i-1];
            smallest[i] = min(smallest[i-1], prices[i]);
            single[i] = max(single[i-1], prices[i] - smallest[i]);

            if (prices[i] <= prices[i-1]) continue;
            for (int j = i-1; j >= 1; j--) {
                if (prices[i] > prices[j]) {
                    if (prices[i] - prices[j] + single[j-1] >= larger[i] + smaller[i]) {
                        larger[i] = max(prices[i] - prices[j], single[j-1]);
                        smaller[i] = min(prices[i] - prices[j], single[j-1]);
                    }
                }
            }
            if (prices[i] - prices[0] >= larger[i] + smaller[i]) {
                larger[i] = prices[i] - prices[0];
                smaller[i] = 0;
            }
        }
        return larger[prices.size()-1] + smaller[prices.size()-1];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}