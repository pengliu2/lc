#include <iostream>
#include <string>
#include <vector>

/*
 * reminders:
 * 1. there shouldn't be space before the first words, be careful
 * 2. my vector for teens starts from "One", so teens[num - 1]
 * 3. in build(), because any digit could be zero, have to check the digit before padding 0
 */

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return string("Zero");
        teens.push_back("One");
        teens.push_back("Two");
        teens.push_back("Three");
        teens.push_back("Four");
        teens.push_back("Five");
        teens.push_back("Six");
        teens.push_back("Seven");
        teens.push_back("Eight");
        teens.push_back("Nine");
        teens.push_back("Ten");
        teens.push_back("Eleven");
        teens.push_back("Twelve");
        teens.push_back("Thirteen");
        teens.push_back("Fourteen");
        teens.push_back("Fifteen");
        teens.push_back("Sixteen");
        teens.push_back("Seventeen");
        teens.push_back("Eighteen");
        teens.push_back("Nineteen");
        teens.push_back("Twenty");

        string ans;
        int ret = build(num / 1000000000, ans);
        if (ret > 0) {
            ans = ans + " Billion";
        }
        num = num % 1000000000;
        ret = build(num / 1000000, ans);
        if (ret > 0) {
            ans = ans + " Million";
        }
        num = num % 1000000;
        ret = build(num / 1000, ans);
        if (ret > 0) {
            ans = ans + " Thousand";
        }
        num = num % 1000;
        build(num, ans);

        return ans;
    }
private:
    vector<string> teens;
    const vector<string> tens{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    int build(int num, string& ans) {
        if (num == 0) return 0;
        if (num / 100 > 0) {
            if (ans.size() != 0)
                ans = ans + " ";
            ans = ans + teens[num/100 - 1] + " Hundred";
        }
        num = num % 100;
        if (num == 0) return 1;
        if (ans.size() != 0)
            ans = ans + " ";
        if (num < 20) {
            ans = ans + teens[num -1 ];
            return 1;
        }
        ans = ans + tens[num / 10 - 2];
        num = num % 10;
        if (num == 0) return 1;
        ans = ans + " " + teens[num - 1];
        return 1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

