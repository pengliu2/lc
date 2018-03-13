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
        vector<vector<vector<int>>> cache = vector<vector<vector<int>>>(2, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for (int i = 1; i <= size; i++) {
            int n0 = count(strs[i - 1]);
            int n1 = strs[i - 1].length() - n0;
            for (int j = 0; j < m+1; j++) {
                for (int k = 0; k < n+1; k++) {
                        if (j >= n0 && k >= n1) {
                            cache[i % 2][j][k] = max(cache[(i - 1) % 2][j][k], cache[(i - 1) % 2][j - n0][k - n1] + 1);
                        } else {
                            cache[i % 2][j][k] = cache[(i - 1) % 2][j][k];
                        }
                }
            }
        }
        return cache[size%2][m][n];
    }

};


int main() {
    Solution slt;
    vector<string> strs{"00", "000"};
    return slt.findMaxForm(strs, 1, 10);
}