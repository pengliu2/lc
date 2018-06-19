#include <iostream>
#include <vector>
#include <algorithm>

/*
 * reminders:
 * 1. naive solution = O(wordDict.size() ^ s.size())
 * 2. memorized = O(wordDict.size() * s.size())
 */

using namespace std;

class SolutionI {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b){return a.size() > b.size();});
        vector<int> visited(s.size(), 0);
        return helper(s, 0, wordDict, visited);
    }

private:
    bool helper(string& s, int index, vector<string>& wordDict, vector<int>& visited) {
        if (index >= s.size()) return true;
        if (visited[index] == 1) return false;
        for(const auto& m : wordDict) {
            if (!equals(s, index, m)) {
                continue;
            }
            bool ret = helper(s, index+m.size(), wordDict, visited);
            if (ret) return true;
        }
        visited[index] = 1;
        return false;
    }

    bool equals(string& s, int index, const string& m) {
        int i = 0;
        for (; index+i < s.size() && i < m.size(); i++) {
            if (s[i+index] != m[i]) return false;
        }
        return i == m.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}