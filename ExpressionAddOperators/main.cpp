#include <iostream>
#include <vector>

using namespace std;
/*
 * reminders:
 * 1. recursively check strings, all indices might need +1 or more
 * 2. first digit could be 0
 * 3. sum or any number might be larger than 2^31
 */

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.size() == 0) return ans;
        string temp;
        temp.resize(num.size()*2 - 1);
        int init = 0;
        if (num[0] == '0') {
            temp[0] = '0';
            helper(temp, 1, num, 1, target, 0, 0, ans);
            return ans;
        }
        for (int i = 0; i < num.size(); i++) {
            temp[i] = num[i];
            init = init*10 + (num[i] - '0');
            helper(temp, i+1, num, i+1, target, 0, init, ans);
        }

        return ans;
    }

private:
    void helper(string &temp, int index, string &num, int pos, int target, int other_val, int cur_val, vector<string>& ans) {
        if (pos >= num.size()) {
            if (cur_val + other_val == target) {
                ans.push_back(temp.substr(0, index));
            }
            return;
        }
        if (num[pos] == '0') {
            temp[index+1] = '0';
            temp[index] = '*';
            helper(temp, index+2, num, pos+1, target, other_val, 0, ans);
            temp[index] = '+';
            helper(temp, index+2, num, pos+1, target, other_val+cur_val, 0, ans);
            temp[index] = '-';
            helper(temp, index+2, num, pos+1, target, other_val+cur_val, 0, ans);
        } else {
            int init = 0;
            for (int i = pos; i < num.size(); i++) {
                init = init * 10 + (num[i] - '0');
                temp[1+index+i-pos] = num[i];
                temp[index] = '*';
                helper(temp, 2+index+i-pos, num, i+1, target, other_val, cur_val*init, ans);
                temp[index] = '+';
                helper(temp, 2+index+i-pos, num, i+1, target, other_val+cur_val, init, ans);
                temp[index] = '-';
                helper(temp, 2+index+i-pos, num, i+1, target, other_val+cur_val, -init, ans);
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}