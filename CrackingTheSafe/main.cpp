#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
#include <set>

using namespace std;

/*
 * reminders:
 * 1. total string lenght is n + power(k, n) - 1
 * 2. don't forget to result[index] = i + '0' before calling next stack, or next stack can't get real last n-1 digits
 * 3. unordered_set is implemented by hash table
 * 4. set is tree, sorted, with which items can be iterated
 */

class Solution {
public:
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string ret(n + total - 1, 'a');
        for (int i = 0; i < n; i++) {
            ret[i] = '0';
        }
        set<int> visited;
        visited.emplace(0);
        helper(ret, n, k, visited, n, total);
        return ret;
    }

    bool helper(string &ret, int n, int k, set<int> &visited, int index, int total) {
        if (index == n+total-1) return true;
        int last = 0;
        for (int i = 0; i < n-1; i++) {
            last = last * 10;
            last += ret[index - (n-1) + i] - '0';
        }
        last *= 10;
        for (int i = 0; i < k; i++) {
            if (visited.count(last+i) != 0) continue;
            visited.emplace((last+i));
            ret[index] = i + '0';
            if (helper(ret, n, k, visited, index+1, total)) {
                return true;
            }
            auto iter = visited.find(last+i);
            visited.erase(iter);
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}