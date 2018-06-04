#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string res(digits);
        helper(ans, digits, 0, res);
        return ans;
    }
private:
    void helper(vector<string> &ans, string& digits, int index, string& res) {
        if (index >= digits.size()) {
            string r(res);
            ans.push_back(r);
            return;
        }

        for (int i = 0; i < map[digits[index] - '0'].size(); i++) {
            res[i] = map[digits[index] - '0'][i];
            helper(ans, digits, index+1, res);
        }
    }

    vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqs", "tuv", "wxyz"};
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}