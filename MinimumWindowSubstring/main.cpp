#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * reminders:
 * 1. to save indices might be better than to save char, that way previous redundant char can be removed when check new window
 * 2. there might be multiple same characters in t!!!
 */

class Solution {
public:
    string minWindow(string s, string t) {
        size_t start = 0;
        size_t len = s.size();
        int found = 0;

        unordered_map<char, int> count;
        unordered_map<char, int> total;
        queue<int> q;

        for (const char c : t) {
            count[c] = 0;
            if (total.count(c) == 0) {
                total[c] = 1;
            } else {
                total[c] += 1;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (count.count(s[i]) == 0) continue;

            if (count[s[i]] < total[s[i]]) {
                found++;
            }
            count[s[i]] += 1;
            q.push(i);

            while (count[s[q.front()]] > total[s[q.front()]]) {
                count[s[q.front()]] -= 1;
                q.pop();

            }

            if (found == t.size()) {
                size_t newlen = i - q.front() + 1;
                if (newlen < len) {
                    start = q.front();
                    len = newlen;
                }
            }
        }

        if (found < t.size()) return string("");
        return s.substr(start, len);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}