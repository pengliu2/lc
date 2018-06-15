#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans = vector<int>(n, 0);
        deque<int> q;
        int cur = -1;
        int ts = 0;
        for (int i = 0; i < logs.size(); i++) {
            vector<int> log = parse(logs[i]);
            if (log[1] == 0) {
                if (cur >= 0) {
                    ans[cur] += log[2] - ts;
                    q.push_back(cur);
                }
                ts = log[2];
                cur = log[0];
            } else {
                ans[cur] += log[2] - ts;
                if (!q.empty()) {
                    cur = q.back();
                    q.pop_back();
                } else {
                    cur = -1;
                }
            }
        }
        return ans;
    }

private:
    vector<int> parse(string& s) {
        vector<int> ans(3, 0);
        int i = 0;
        int id = 0;
        while (s[i] != ':') {
             id = id * 10 + (s[i] - '0');
        }
        if(s[++i] == 's') {
            ans[1] = 0;
            i += 6;
        } else {
            ans[1] = 1;
            i += 4;
        }
        int ts = 0;
        while (i < s.size()) {
            ts = ts*10 + (s[i] - '0');
        }
        ans[0] = id;
        ans[2] = ts;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}