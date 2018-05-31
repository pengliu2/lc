#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        auto p = valid(s);
        left = p.first;
        right = p.second;
        vector<string> ans;
        helper(left, right, s, 0, ans);
        return ans;
    }

private:
    void helper(int left, int right, string rem, int index, vector<string>& ans) {
        if (left == 0 && right == 0) {
            auto p = valid(rem);
            if (p.first == 0 && p.second == 0)
                ans.push_back(rem);
            return;
        }

        for (int i = index; i < rem.size(); i++) {
            if (rem[i] == '(' && left > 0) {
                if (i > index && rem[i-1] == '(') continue;
                helper(left - 1, right, rem.substr(0, i) + rem.substr(i+1), i, ans);
            } else if (rem[i] == ')' && right > 0) {
                if (i > index && rem[i-1] == ')') continue;
                helper(left, right - 1, rem.substr(0, i) + rem.substr(i+1), i, ans);
            }
        }
    }
    pair<int, int> valid(string s) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                left++;
            else if(s[i] == ')') {
                if (left <= 0)
                    right++;
                else
                    left--;
            }
        }
        return pair<int, int>{left, right};
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}