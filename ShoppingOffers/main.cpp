#include <iostream>
#include "../myheader.h"

/*
 * reminder:
 * 1. be careful: vector<int> xxx{} and xxx()
 * 2. SolutionII is pure dfs, TLE, because time complexity is O(k^n)
 * 3. dp time complexity is O(n*k)
 * 4. SolutionIII is other's DFS solution, the pruning method is to check if special offer price > direct buy
 */

void operator-=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++) a[i] -= b[i];
}

void operator+=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++) a[i] += b[i];
}

bool operator<(const vector<int> &a, int b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] < b) return true;
    return false;
}

bool operator<=(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < b.size(); i++)
        if (a[i] > b[i]) return false;
    return true;
}

bool operator>(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > b[i]) return true;
    return false;
}

class SolutionIV {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        vector<map<int, int>> cache(1);
        cache[0][0] = 0;
        for (const auto & s : special) {
            if (direct(s, price) <= s.back()) continue;
            cache.push_back(map<int, int>{});
            for (const auto &c : cache[cache.size() - 2]) {
                auto v = unsign(c.first, needs.size());
                auto p = c.second;
                cache.back()[c.first] = c.second;
                v += s;
                p += s.back();
                while (v <= needs) {
                    int si = sign(v);
                    if (cache.back().count(si))
                        cache.back()[si] = min(cache.back()[si], p);
                    else
                        cache.back()[si] = p;
                    v += s;
                    p += s.back();
                }
            }
        }
        int ret = direct(needs, price);
        for (const auto & c : cache.back()) {
            ret = min(ret, c.second + compute(needs, unsign(c.first, needs.size()), price));
        }
        return ret;
    }

    inline int compute(const vector<int> &needs, const vector<int> &have, const vector<int> &price) {
        int ret = 0;
        for (int i = 0; i < needs.size(); i++) {
            ret += (needs[i] - have[i]) * price[i];
        }
        return ret;
    }

    inline int direct(const vector<int> &needs, const vector<int> &prices) {
        int ret = 0;
        for (int i = 0; i < prices.size(); i++) {
            ret += needs[i]*prices[i];
        }
        return ret;
    }
private:
    int sign(const vector<int> &a) {
        int ret = 0;
        for (int i = a.size()-1; i >= 0; i--) {
            ret = (ret << 4) + a[i];
        }
        return ret;
    }

    vector<int> unsign(int i, int size) {
        vector<int> ret;
        for (int j = 0; j < size; j++) {
            ret.push_back(i & 0x0F);
            i = i >> 4;
        }
        return ret;
    }
};

class SolutionIII {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if (needs < 0)
            return INT_MAX;

        int m = cost + needs * price;

        for (auto &offer : special) {
            if (cost + offer.back() >= m) // pruning
                continue;
            needs -= offer;
            m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
            needs += offer;
        }

        return m;
    }
};

class SolutionII {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int count = price.size();
        if (count == 0) return 0;
        for (int i = 0; i < count; i++) {
            vector<int> v(count, 0);
            v.push_back(price[i]);
            v[i] = 1;
            special.push_back(v);
        }
        return dfs(special, needs);
    }
private:
    int dfs(const vector<vector<int>> &special, vector<int> &needs) {

        bool done = true;
        for (const int i : needs) {
            if (i != 0) {
                done = false;
                break;
            }
        }
        if (done) return 0;

        int ret = INT_MAX;
        for (const vector<int> & s : special) {
            bool good = true;
            for (int i = 0; i < needs.size(); i++) {
                if (s[i] > needs[i]) {
                    good = false;
                    break;
                }
            }
            if (!good) continue;

            for (int i = 0; i < needs.size(); i++) {
                needs[i] -= s[i];
            }
            if (s.back() > ret) continue;
            int r = dfs(special, needs);
            if (r != INT_MAX)
                ret = min(ret, r + s.back());

            for (int i = 0; i < needs.size(); i++) {
                needs[i] += s[i];
            }
        }
        return ret;
    }
};

class SolutionI {
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