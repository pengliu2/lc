#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unistd.h>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int max_n = 0;
        map<int, int> netid;
        map<int, set<int>> m;
        for (auto &e : edges) {
            if (netid.count(e[0]) != 0 && netid.count(e[1]) != 0) {
                if (netid[e[0]] == netid[e[1]])
                    return e;
            } else {
                if (netid.count(e[0]) == 0)
                    netid[e[0]] = e[0];
                if (netid.count(e[1]) == 0)
                    netid[e[1]] = e[1];
            }

            int newid = min(netid[e[0]], netid[e[1]]);

            if (netid[e[0]] != newid) {
                set<int> v;
                sync(e[0], netid, m, newid, v);
            }

            if (netid[e[1]] != newid) {
                set<int> v;
                sync(e[1], netid, m, newid, v);
            }

            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
    }

    void sync(int start, map<int, int>& netid, map<int, set<int>>& m, int newid, set<int>& visited) {
        netid[start] = newid;
        visited.insert(start);

        auto neighbors = m[start];
        for (auto &n : neighbors) {
            if (visited.count(n) != 0) continue;
            sync(n, netid, m, newid, visited);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}