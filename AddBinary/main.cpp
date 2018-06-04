#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string longstr = a.size() > b.size() ? a : b;
        string shortstr = a.size() > b.size() ? b : a;
        string ans(longstr);
        int carry = 0;
        for (int i = 0; i < shortstr.size(); i++) {
            int t = (ans[ans.size() - 1 - i] - '0') + (shortstr[shortstr.size() - 1 - i] - '0') + carry;
            switch(t) {
                case 0:
                    carry = 0;
                    break;
                case 1:
                    ans[ans.size() - 1 - i] = '1';
                    carry = 0;
                    break;
                case 2:
                    ans[ans.size() - 1 - i] = '0';
                    carry = 1;
                    break;
                case 3:
                    ans[ans.size() - 1 - i] = '1';
                    carry = 1;
                    break;
            }
        }
        for (int i = ans.size() - shortstr.size() - 1; i >= 0; i--) {
            if (carry == 0) break;
            if (ans[i] == '1') {
                ans[i] == '0';
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry = 1) {
            return "1" + ans;
        } else {
            return ans;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}