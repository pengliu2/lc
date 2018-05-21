#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/*
 * reminders:
 * 1. when initilizing cache size = item count + 1 to use cache[0] as initial state, a.k.a. virtual item, don't forget to adapt all other places
 * 
 */

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        auto k_cache = vector<vector<int>>(26, vector<int>());
        for (int i = 0; i < key.length(); i++) {
            k_cache[key[i]-'a'].push_back(i);
        }

        cache = vector<vector<vector<int>>>(key.length() + 1, vector<vector<int>>());

        for (int i = 0; i < ring.length(); i++) {
            if (k_cache[ring[i] - 'a'].empty()) continue;
            for (auto & v : k_cache[ring[i] - 'a']) {
                cache[v + 1].push_back(vector<int>{i, INT_MAX});
            }
        }

        cache[0].push_back(vector<int>{0, 0});

        int r = INT_MAX;
        for (int i = 1; i < key.length()+1; i++) {
            int ret = INT_MAX;
            for (const auto & v : cache[i-1]) {
                int pos = v[0];
                int cost = v[1];
                for (auto & c : cache[i]) {
                    int newpos = c[0];
                    int m = max(newpos, pos) - min(newpos, pos);
                    m = min(m, (int)ring.length() - m);
                    c[1] = min(c[1], m + 1 + cost);
                    ret = min(ret, c[1]);
                }
            }
            if (i == key.length())
                r = ret;
        }
        return r;
    }
private:
    vector<vector<vector<int>>> cache;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}