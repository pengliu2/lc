#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        auto tcache = unordered_map<int, int>();
        int total_items = price.size();

        tcache[0] = 0;
        int target = 0;
        for (int i = total_items - 1; i >= 0; i--) {
            target = (target << 4) + needs[i];
        }
        if (target == 0) return 0;

        vector<int> cur(total_items);

        for (int k = 1; k <= 36; k++) {
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
                    for (int i = total_items - 1; i >= 0; i--) {
                        if (cur[i] + s[i] > needs[i] ) {
                            new_items = -1;
                            break;
                        }
                        new_items = (new_items << 4) + (cur[i] + s[i]);
                    }
                    if (new_items < 0) continue;

                    if (tcache.count(new_items) == 0) {
                        tcache[new_items] = tcache[items] + s[total_items];
                    } else {
                        tcache[new_items] = min(tcache[new_items], tcache[items] + s[total_items]);
                    }
                }
            }
        }
        int ret = INT_MAX;
        for (const auto & c: tcache) {
            int items = c.first;
            int p = c.second;
            for (int i = 0; i < total_items; i++) {
                cur[i] = items & 0x0F;
                items = items >> 4;
                cur[i] = needs[i] - cur[i];
                p += cur[i] * price[i];
            }
            ret = min(ret, p);
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}