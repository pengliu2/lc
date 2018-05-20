#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, &index);
    }
private:
    string helper(string &s, int *index) {
        string ret;
        while (*index < s.length() && s[*index] != ']') {
            if (s[*index] <= '9' && s[*index] >= '0') {
                int times = str2num(s, index);
                *index = *index + 1;
                string r = helper(s, index);
                for (int i = 0; i < times; i++)
                    ret = ret + r;
            } else {
                ret.push_back(s[*index]);
                *index = *index + 1;
            }
        }
        *index += 1;
        return ret;
    }

    int str2num (string &s, int *index) {
        int ret = 0;
        do {
            ret = ret * 10 + (s[*index] - '0');
            *index = *index + 1;
        } while (s[*index] <= '9' && s[*index] >= '0');

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}