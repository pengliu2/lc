#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * reminder:
 * 1. Solution I: TLE
 * 2. layer better to be target layer, thus when next layer is larger than index, then we win
 *
 */
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        for (const string & a : allowed) {
            rules[a.substr(0, 2)].push_back(a.substr(2, 1));
        }
        string cur{""};
        return dfs(bottom, 0, cur);
    }
private:
    unordered_map<string, vector<string>> rules;
    bool dfs(const string &prev, int index, string & cur) {
        if (prev.length() == 1) return true;
        if (index == prev.length() - 1) {
            const string p = cur;
            string c{""};
            if (dfs(p, 0, c))
                return true;
            else
                return false;
        }
        for (const auto r : rules[prev.substr(index, 2)]) {
            cur += r;
            if (dfs(prev, index + 1, cur))
                return true;
            cur.pop_back();
        }
        return false;
    }
};

class SolutionI {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string & a : allowed) {
            rules[a.substr(0, 2)].push_back(a.substr(2, 1));
        }
        string p = bottom.substr(0, 1);
        string c = bottom.substr(1, 1);
        return dfs(bottom, 1, 1, p, c);
    }
private:
    unordered_map<string, vector<string>> rules;
    bool dfs(string bottom, int index, int layer, string &prev, string &cur) {
        if (layer == bottom.size()) return true;
        if (layer > index) {
            string p = cur;
            string c = bottom.substr(index + 1, 1);

            if (dfs(bottom, index + 1, 1, p, c))
                return true;
            else
                return false;
        }
        for (const auto r : rules[prev.substr(layer - 1, 1) + cur.substr(layer - 1, 1)]) {
            cur += r;
            if (dfs(bottom, index, layer+1, prev, cur))
                return true;
            cur.pop_back();
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}