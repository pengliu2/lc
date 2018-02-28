#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

using rules=map<string, map<string, double>>;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        rules m1;

        int size = values.size();
        for (int i = 0; i < size; i++) {
            auto first = equations[i].first;
            auto second = equations[i].second;
            m1[first].emplace(second, values[i]);
            m1[second].emplace(first, 1/values[i]);
        }

        vector<double> results;
        for (const auto & q: queries) {
            double up = 1.0;
            double down = 1.0;
            set<string> visited;

            bool ret = dfs(q.first, m1, visited, q.second, up, down);
            if (ret)
                results.push_back(up);
            else
                results.push_back(-1.0);
        }
        return results;
    }

    bool dfs(string node, rules &m1, set<string> &visited, string target, double &up, double &down) {
        if (m1.count(node) == 0) return false;
        if (node == target) return true;
        visited.insert(node);
        auto c1 = m1[node];
        for (auto & c : c1) {
            if (visited.count(c.first) != 0 ) continue;
            up *= c.second;
            bool ret = dfs(c.first, m1, visited, target, up, down);
            if (ret) return ret;
            up /= c.second;
        }
        return false;
    }
};

