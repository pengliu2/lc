#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. following statements have strange behavior:
 * string & small = s1;
 * string & large = s2;
 * small = s2;
 * large = s1;
 *
 * reference & is actually pointer
 *
 * 2. should firstly choose and only keep shared characters
 * */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total = 0;
        for (int i = 0; i < s1.size(); i++) {
            total += s1[i];
        }
        for (int i = 0; i < s2.size(); i++) {
            total += s2[i];
        }

        auto cache = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));

        int ret = dfs(s1, s2, 0, 0, cache);
        return total - ret*2;
    }

    int dfs(const string &s1, const string &s2, int index1, int index2, vector<vector<int>> &cache) {
        if ((index1 >= s1.size()) || (index2 >= s2.size())) return 0;
        if (cache[index1][index2] >= 0) return cache[index1][index2];

        int ret1 = dfs(s1, s2, index1+1, index2, cache);
        for (int i = index2; i < s2.size(); i++) {
            if (s2[i] == s1[index1]) {
                ret1 = max(ret1, s2[i] + dfs(s1, s2, index1+1, i+1, cache));
                break;
            }
        }

        cache[index1][index2] = ret1;
        return ret1;
    }
};


int main() {
    string s1("abcdedf");
    string s2("knopqrs");
    string &ss1 = s1;
    string &ss2 = s2;

    ss1[1] = '1';

    cout << s1 << endl;
    cout << s2 << endl;
    cout << ss1 << endl;
    cout << ss2 << endl;
    char c;
    cin >> c;

    return 0;
}