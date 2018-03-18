#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() < 2) return pairs.size();

        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b){return a[0]==b[0]? a[1] < b[1] : a[0] < b[0];});
        vector<int> &last = pairs[0];
        int ret = 1;

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[i][0] > last[1]) {
                last = pairs[i];
                ret += 1;
            } else if (pairs[i][1] < last[1]) {
                last = pairs[i];
            }
        }

        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}