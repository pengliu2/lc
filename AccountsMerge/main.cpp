#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>


using namespace std;

/*
 * reminder for SolutionII:
 * 1. iterator cannot be const in for loop
 *
 * reminder for SolutionI:
 * 1. for this problem, rank doesn't matter because each node directly connect to root
 * 2. 1 is wrong, ranks do matter: 2 trees might be merged at the end of accounts list
 * 3. for this problem, first string is name, has to be handled separately when iterate rules
 * 4. in inner loop, else block, still needs find(node) in case parent has been set by other emails of this account
 */

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> email_to_group;
        vector<vector<int>> grouping(accounts.size(), vector<int>(2, -1));
        for (int i = 0; i < accounts.size(); i++) {
            grouping[i][0] = i;
            grouping[i][1] = 1;
        }

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (email_to_group.count(accounts[i][j])) {
                    unite(grouping, email_to_group[accounts[i][j]], i);
                } else {
                    email_to_group[accounts[i][j]] = i;
                }
            }
        }
        
        map<int, set<string>> results;
        map<int, string> names;
        for (auto iter = email_to_group.begin(); iter != email_to_group.end(); iter++) {
            int g = find(grouping, iter->second);
            if (results.count(g) == 0) {
                results[g] = set<string>{iter->first};
                names[g] = string(accounts[g][0]);
            } else {
                results[g].insert(iter->first);
            }
        }

        vector<vector<string>> ans;

        for (auto iter = results.begin(); iter != results.end(); iter++) {
            ans.push_back(vector<string>{names[iter->first]});
            std::copy(iter->second.begin(), iter->second.end(), ans[ans.size()-1].begin()+1);
        }
        return ans;
    }

private:
    int find(vector<vector<int>> &grouping, int i) {
        if (grouping[i][0] == i) return i;
        int ret = find(grouping, grouping[i][0]);
        grouping[i][0] = ret;
        return ret;
    }

    void unite(vector<vector<int>>& grouping, int i, int j) {
        int p1 = find(grouping, i);
        int p2 = find(grouping, j);
        if (p1 == p2) return;
        if (grouping[p1][1] > grouping[p2][1]) {
            grouping[p2][0] = p1;
        } else if (grouping[p2][1] > grouping[p1][1]) {
            grouping[p1][0] = p2;
        } else {
            grouping[p1][0] = p2;
            grouping[p2][1] += 1;
        }
    }

};

class SolutionII {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> grouping(accounts.size(), -1);
        for (int i = 0; i < accounts.size(); i++) {
            grouping[i] = i;
        }

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts.size(); j++) {
                if (helper(accounts, i, j)) {
                    unite(grouping, i, j);
                }
            }
        }

        vector<set<string>> results;
        for (int i = 0; i < grouping.size(); i++) {
            int g = find(grouping, i);
            if (g >= results.size()) {
                results.push_back(set<string>{accounts[i].begin()+1, accounts[i].end()});
            } else {
                results[g].insert(accounts[i].begin()+1, accounts[i].end());
            }
        }

        vector<vector<string>> ans;
        for (int i = 0; i < results.size(); i++) {
            ans.push_back(vector<string>{results[i].begin(), results[i].end()});
        }
        return ans;
    }

private:
    int find(vector<int>& grouping, int i) {
        if (grouping[i] == i) return i;
        int ret = find(grouping, grouping[i]);
        grouping[i] = ret;
        return ret;
    }

    int unite(vector<int>& grouping, int i, int j) {
        int p1 = find(grouping, i);
        int p2 = find(grouping, j);
        if (p1 == p2) return p1;
        if (p1 < p2) {
            grouping[p2] = p1;
            return p1;
        } else {
            grouping[p1] = p2;
            return p2;
        }
    }

    bool helper(vector<vector<string>>& accounts, int i1, int i2) {
        if (accounts[i1][0] != accounts[i2][0]) return false;
        for (int i = 1; i < accounts[i1].size(); i++) {
            for (int j = 1; j < accounts[i2].size(); j++) {
                if (accounts[i1][i] == accounts[i2][j]) return true;
            }
        }
        return false;
    }
};


class SolutionI {
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