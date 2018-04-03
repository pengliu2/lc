#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
 * reminder:
 * 1. for this problem, rank doesn't matter because each node directly connect to root
 * 2. 1 is wrong, ranks do matter: 2 trees might be merged at the end of accounts list
 * 3. for this problem, first string is name, has to be handled separately when iterate rules
 * 4. in inner loop, else block, still needs find(node) in case parent has been set by other emails of this account
 */

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> umap;
        parents = vector<vector<int>>(accounts.size(), vector<int>{-1, 1});
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (umap.count(accounts[i][j])) {
                    int p1 = find(i);
                    int p2 = find(umap[accounts[i][j]]);
                    parents[i][0] = bind(p1, p2);
                } else {
                    parents[i][0] = find(i);
                    parents[i][1] = 1;
                    umap[accounts[i][j]] = parents[i][0];
                }
            }
        }

        map<int, vector<string>> agg;
        for (const auto &u : umap) {
            int p = find(parents[u.second][0]);
            if (agg.count(p) == 0) {
                agg[p].push_back(accounts[p][0]);
            }
            agg[p].push_back(u.first);
        }

        vector<vector<string>> ret;
        for (const auto &u : agg) {
            ret.push_back(u.second);
            sort(ret.back().begin() + 1, ret.back().end());
        }
        return ret;
    }
private:
    vector<vector<int>> parents;
    int find(int node) {
        if (parents[node][0] == -1) return node;
        if (parents[node][0] == node) return node;
        int p = find(parents[node][0]);
        parents[node][0] = p;
        return p;
    }

    int bind(int node1, int node2) {
        if (parents[node1][1] > parents[node2][1]) {
            parents[node2][0] = node1;
            return node1;
        } else if (parents[node1][1] < parents[node2][1]) {
            parents[node1][0] = node2;
            return node2;
        } else {
            parents[node1][0] = node2;
            parents[node2][1] += 1;
            return node2;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}