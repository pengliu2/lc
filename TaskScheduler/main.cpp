#include <iostream>
#include <algorithm>

/*
 * reminders:
 * 1. using char - 'A' as index, dont forget to use the same form for all indexing
 */

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> count(26, 0);
        int most = 0;
        for (int i = 0; i < tasks.size(); i++) {
            count[tasks[i] - 'A'] += 1;
            most = max(most, count[tasks[i] - 'A']);
        }

        if (tasks.size() / (n+1) >= most) return tasks.size();

        int ans = (most-1) * (n+1);
        for (int i = 0; i < 26; i++) {
            if (count[i] == most) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}