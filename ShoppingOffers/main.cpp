#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        auto tcache = vector<unordered_map<int, int>>(37, unordered_map<int, int>());
        int total_items = price.size();

        tcache[0][0] = 0;
        int target = 0;
        for (int i = total_items - 1; i >= 0; i--) {
            target = (target << 4) + needs[i];
        }
        if (target == 0) return 0;

        vector<int> cur(total_items);

        for (int k = 1; k <= 36; k++) {
            auto & cache = tcache[k-1];
            auto & ncache = tcache[k];

            for (const auto & c : cache) {
                int items = c.first;
                int total_price = c.second;
                for (int i = 0; i < total_items; i++) {
                    cur[i] = items & 0x0F;
                    items = items >> 4;
                }
                items = c.first;
                for (int i = 0; i < total_items; i++) {
                    if (cur[i] >= needs[i]) continue;

                    int cur_items = items + (1 << (4*i));
                    if (ncache.count(cur_items) == 0) {
                        ncache[cur_items] = cache[items] + price[i];
                    } else {
                        ncache[cur_items] = min(ncache[cur_items], cache[items] + price[i]);
                    }
                }

                for (const auto &s : special) {
                    int new_items = 0;
                    for (int i = total_items - 1; i >= 0; i--) {
                        if (cur[i] + s[i] > needs[i] ) {
                            new_items = -1;
                            break;
                        }
                        new_items = (new_items << 4) + (cur[i] + s[i]);
                    }
                    if (new_items < 0) continue;

                    if (ncache.count(new_items) == 0) {
                        ncache[new_items] = cache[items] + s[total_items];
                    } else {
                        ncache[new_items] = min(ncache[new_items], cache[items] + s[total_items]);
                    }
                }
            }
        }

        int ret = INT_MAX;
        for (int i = 0; i < tcache.size(); i++) {
            if (tcache[i].count(target)) {
                ret = min(ret, tcache[i][target]);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}