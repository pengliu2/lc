#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size() + 1, '0');

        int index = ans.size() - 1;
        for (int i = num1.size() - 1; i >= 0; i--) {
            if (num1[i] != '0')
                helper(ans, index, num1[i] - '0', num2);
            index--;
        }
        for (index = 0; index < ans.size() - 1; index++) {
            if (ans[index] != '0') break;
        }
        return ans.substr(index);
    }
private:
    void helper(string& ans, int index, int times, string& num2) {
        int carry = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            int sum = (num2[i] - '0') * times + (ans[index] - '0') + carry;
            ans[index] = sum % 10 + '0';
            carry = sum / 10;
            index--;
        }

        while (carry != 0) {
            int sum = ans[index] - '0' + carry;
            ans[index] = sum % 10 + '0';
            carry = sum / 10;
            index--;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}