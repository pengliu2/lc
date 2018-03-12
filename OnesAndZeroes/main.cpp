#include <iostream>
#include "../myheader.h"

int count(const string & str, char a) {
    int total = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == a) {
            total++;
        }
    }
    return total;
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        if (size == 0 ) return 0;

        auto cache = unordered_map<int, int>();
        int ret = 0;
        ret = dfs(strs, m, n, cache, 0);
        return ret;
    }

    int dfs(vector<string>& strs, int m, int n, unordered_map<int, int> &cache, int index) {
        if (cache.count(index) == 0) {
            cache[index] = count(strs[index], '0');
        }
        int newm = m - cache[i];
        int newn = n - (strs[i].size() - cache[i]);

        if (newm >= 0 && newn >= 0)
             = max(ret, dfs(strs, newm, newn, used, cache)+1);
        ret = max(ret, dfs(strs, m, n, used, cache));

        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}