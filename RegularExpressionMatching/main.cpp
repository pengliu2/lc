#include <iostream>
#include <string>
/*
 * reminders:
 * 1. when next character is *, call helper again with only pattern index +2, which means matching 0
 * then use a loop to match 1 to n characters in s, as long as s can match
 */

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }
private:
    bool helper(string& s, int index1, string& p, int index2) {
        if (index1 == s.size() && index2 == p.size()) return true;
        if (index1 < s.size() && index2 == p.size()) return false;

        if (index2 < p.size() - 1 && p[index2+1] == '*') {
            if (p[index2] != '.' && p[index2] != s[index1]) {
                return helper(s, index1, p, index2+2);
            } else {
                bool ret = helper(s, index1, p, index2+2);
                if (ret) return true;
                for (int i = index1; i < s.size(); i++) {
                    if (p[index2] != '.' && s[i] != s[index1]) break;
                    ret = helper(s, i+1, p, index2+2);
                    if (ret) return true;
                }
                return false;
            }
        }

        if (p[index2] != '.' && p[index2] != s[index1]) return false;

        return helper(s, index1+1, p, index2+1);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}