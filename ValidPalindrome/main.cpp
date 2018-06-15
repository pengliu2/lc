#include <iostream>
#include <string>

/*
 * reminders:
 * 1. don't forget to increase or decrease indices
 * 2. question actually states alphanumeric considered, not just alphabet
 */

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        bool ret = true;
        while (start < end) {
            while ((start < s.size()) && (!isAB(s[start])))
                start++;
            while ((end >= 0) && (!isAB(s[end])))
                end--;
            if (start >= s.size() || end < 0) return ret;
            if (!equals(s[start], s[end])) return false;
            start++;
            end--;
        };

        return true;
    }

private:
    bool isAB(char c) {
        return (c >= 'a' && c <= 'z')||((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9'));
    }

    bool equals(char a, char b) {
        if (a >= 'a' && a <= 'z') {
        } else if (a >= 'A' && a <='Z'){
            a = a - 'A' + 'a';
        } else {
        }

        if (b >= 'a' && b <= 'z') {
        } else if (b >= 'A' && b <='Z'){
            b = b - 'A' + 'a';
        } else {
        }
        return a==b;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}