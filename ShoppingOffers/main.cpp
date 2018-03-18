#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        auto ncache = vector<unordered_map<int, int>>(37, unordered_map<int, int>());
        int total_items = price.size();

        ncache[0][0] = 0;
        int ret = 0;
        int target = 0;
        for (int i = total_items - 1; i >= 0; i--) {
            target = (target << 4) + needs[i];
            ret += price[i] * needs[i];

        }
        if (ret == 0) return 0;
        if (target == 0) return 0;

        vector<int> cur(total_items);

        for (int k = 1; k <= 36; k++) {
            auto &tcache = ncache[k-1];
            auto &cache = ncache[k];
            for (const auto & c : tcache) {
                int items = c.first;
                int total_price = c.second;
                for (int i = 0; i < total_items; i++) {
                    cur[i] = items & 0x0F;
                    items = items >> 4;
                }
                items = c.first;
                for (const auto &s : special) {
                    int new_items = 0;
                    int new_price = 0;
                    for (int i = total_items - 1; i >= 0; i--) {
                        if (cur[i] + s[i] > needs[i] ) {
                            new_items = -1;
                            break;
                        }
                        new_items = (new_items << 4) + (cur[i] + s[i]);
                        new_price += (needs[i] - cur[i] - s[i]) * price[i];
                    }
                    if (new_items < 0) continue;

                    if (cache.count(new_items) == 0) {
                        cache[new_items] = tcache[items] + s[total_items];
                    } else {
                        cache[new_items] = min(cache[new_items], tcache[items] + s[total_items]);
                    }
                    ret = min(ret, cache[new_items] + new_price);
                }
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}