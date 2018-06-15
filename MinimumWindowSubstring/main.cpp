#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

/*
 * reminders:
 * 1. to save indices might be better than to save char, that way previous redundant char can be removed when check new window
 * 2. there might be multiple same characters in t!!!
 * 3. solutionII removed queue but it's still slow
 */

class Solution {
public:
    string minWindow(string s, string t) {
        int ans = 0;
        int len = s.size();
        int found = 0;

        vector<int> count(256, -INT_MAX);

        for (const char c : t) {
            if (count[c] == -INT_MAX) {
                count[c] = 1;
            } else {
                count[c] += 1;
            }
        }

        int start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == -INT_MAX) continue;

            if (start < 0) start = i;
            if (count[s[i]] > 0)
                found++;
            count[s[i]] -= 1;

            while (count[s[start]] < 0) {
                count[s[start]] += 1;
                for (int j = start+1; j <= i; j++) {
                    if (count[s[j]] != -INT_MAX) {
                        start = j;
                        break;
                    }
                }
            }

            if (found == t.size()) {
                size_t newlen = i - start + 1;
                if (newlen < len) {
                    ans = start;
                    len = newlen;
                }
            }
        }

        if (found < t.size()) return string("");
        return s.substr(ans, len);
    }
};


class SolutionII {
public:
    string minWindow(string s, string t) {
        int ans = 0;
        int len = s.size();
        int found = 0;

        unordered_map<char, int> count;

        for (const char c : t) {
            if (count.count(c) == 0) {
                count[c] = 1;
            } else {
                count[c] += 1;
            }
        }

        int start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (count.count(s[i]) == 0) continue;
            if (start < 0) start = i;
            if (count[s[i]] > 0)
                found++;
            count[s[i]] -= 1;

            while (count[s[start]] < 0) {
                count[s[start]] += 1;
                for (int j = start+1; j <= i; j++) {
                    if (count.count(s[j])) {
                        start = j;
                        break;
                    }
                }
            }

            if (found == t.size()) {
                size_t newlen = i - start + 1;
                if (newlen < len) {
                    ans = start;
                    len = newlen;
                }
            }
        }

        if (found < t.size()) return string("");
        return s.substr(ans, len);
    }
};


class SolutionI {
public:
    string minWindow(string s, string t) {
        size_t ans = 0;
        size_t len = s.size();
        int found = 0;

        unordered_map<char, int> count;

        for (const char c : t) {
            if (count.count(c) == 0) {
                count[c] = 1;
            } else {
                count[c] += 1;
            }
        }

        size_t start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (count.count(s[i]) == 0) continue;

            if (start < 0) start = i;
            if (count[s[i]] > 0)
                found++;
            count[s[i]] -= 1;

            while (count[s[start]] < 0) {
                count[s[start]] += 1;
                for (int j = start+1; j <= i; j++) {
                    if (count.count(s[j])) {
                        start = j;
                        break;
                    }
                }
            }

            if (found == t.size()) {
                size_t newlen = i - start + 1;
                if (newlen < len) {
                    ans = start;
                    len = newlen;
                }
            }
        }

        if (found < t.size()) return string("");
        return s.substr(ans, len);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}