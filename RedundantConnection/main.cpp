#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int max_n = 0;
        map<int, int> netid;
        map<int, set<int>> m;
        for (auto &e : edges) {
            int newid;
            if (netid.count(e[0]) != 0 && netid.count(e[1]) != 0) {
                if (netid[e[0]] == netid[e[1]])
                    return e;
                newid = min(netid[e[0]], netid[e[1]]);
            } else {
                newid = e[0];
                if (netid.count(e[0]) != 0){
                    newid = netid[e[0]];
                }
                if (netid.count(e[1]) != 0) {
                    newid = min(newid, netid[e[1]]);
                }
            }

            if (netid.count(e[0]) != 0 && newid != netid[e[0]]) {
                set<int> v;
                sync(e[0], netid, m, newid, v);
            } else {
                netid[e[0]] = newid;
            }

            if (netid.count(e[1]) != 0 && newid != netid[e[1]]) {
                set<int> v;
                sync(e[1], netid, m, newid, v);
            } else {
                netid[e[1]] = newid;
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