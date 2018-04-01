#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unistd.h>

using namespace std;

/* reminder:
 * 1. constructed rules must accommodate all numbers, which might be more than edges
 * 2. () isn't needed for class variable declaration.
 * 3. Shouldn't construct all the rules like in SolutionII
 *    Should add one rule and then do one search
 * 4. but SolutionIII is still not union find, it's dfs
 * */

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> rel(edges.size() + 1, -1);
        for (const auto &e : edges) {
            int p1 = findroot(rel, e[0]);
            int p2 = findroot(rel, e[1]);
            if (p1 == p2) return e;
            rel[p2] = p1;
        }
        return vector<int>(2,0);
    }

    int findroot(vector<int> rel, int item) {
        if (rel[item] == -1) return item;
        return findroot(rel, rel[item]);
    }
};

class SolutionIII {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> rules(edges.size() + 1, vector<int>());
        for (const auto &v : edges) {
            rules[v[0]].push_back(v[1]);
            rules[v[1]].push_back(v[0]);

            if(findcycle(v[0], rules, v[1], v[0]))
                return v;
        }

        return vector<int>();
    }
    bool findcycle(int caller, vector<vector<int>> &rules, int next, int origin) {
        if (next == origin) return true;
        for (const auto &r : rules[next]) {
            if (r == caller) continue;
            if (findcycle(next, rules, r, origin))
                return true;
        }
        return false;
    }
};

class SolutionII {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> rules(edges.size(), vector<int>());
        int number = 0;
        for (auto &v : edges) {
            if (rules[v[0]].empty()) {
                number++;
            }
            if (rules[v[1]].empty()) {
                number++;
            }
            rules[v[0]].push_back(v[1]);
            rules[v[1]].push_back(v[0]);
        }

        vector<int> used(number+1, 0);

        for (const auto &v : edges) {
            if(findcycle(v[0], rules, v[1], v[0]))
                return v;
        }

        return vector<int>();
    }
    bool findcycle(int caller, vector<vector<int>> &rules, int next, int origin) {
        if (next == origin) return true;
        for (const auto &r : rules[next]) {
            if (r == caller) continue;
            if (findcycle(next, rules, r, origin))
                return true;
        }
        return false;
    }
};

class SolutionI {
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