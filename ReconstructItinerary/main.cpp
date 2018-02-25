#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, map<string, int>> m;
        int total = 0;
        for (auto p : tickets) {
            if (m.count(p.first) == 0) {
                m[p.first] = map<string, int>();
                m[p.first][p.second] = 1;
            } else if (m[p.first].count(p.second) == 0){
                m[p.first][p.second] = 1;
            } else {
                m[p.first][p.second] += 1;
            }
            total += 1;
        }
        vector<string> ret;
        ret.push_back(string("JFK"));
        dfs(m, ret, total);
        return ret;
    }

    bool dfs(map<string, map<string, int>> & m, vector<string>& s, int remain) {
        if (remain == 0) return true;
        for (auto p : s) {
            cout << p;
        }
        cout << endl;

        auto& candidates = m[s.back()];
        for (auto& c : candidates) {
            if (c.second == 0) continue;
            c.second -= 1;
            remain -= 1;
            s.push_back(c.first);
            bool ret = dfs(m, s, remain);
            if (ret) return true;
            s.erase(s.end() - 1);
            remain += 1;
            c.second += 1;
        }
        return false;
    }
};

int main() {
    Solution slt;
    vector<pair<string, string>> tickets;
    tickets.push_back({"JFK", "SFO"});
    tickets.push_back({"JFK", "ATL"});
    tickets.push_back({"SFO", "ATL"});
    tickets.push_back({"ATL", "JFK"});
    tickets.push_back({"ATL", "SFO"});
    auto ret = slt.findItinerary(tickets);
    char a;
    cin >> a;
    return 0;
}
