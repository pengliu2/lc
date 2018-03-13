#include <iostream>
#include "../myheader.h"

inline int count(const string & str) {
    int total = 0;
    for (const char c : str){
        if (c == '0') {
            total++;
        }
    }
    return total;
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<int>> cache = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        int i = 1;
        for (const string & s : strs) {
            int n0 = count(s);
            int n1 = s.length() - n0;
            for (int j = m; j >= n0; j--) {
                for (int k = n; k >= n1; k--) {
                    cache[j][k] = max(cache[j][k], cache[j - n0][k - n1] + 1);
                }
            }
            i++;
        }
        return cache[m][n];
    }

};

int main() {
    Solution slt;
    vector<string> strs{"00", "000"};
    return slt.findMaxForm(strs, 1, 10);
}