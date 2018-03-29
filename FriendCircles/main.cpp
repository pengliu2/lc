#include <iostream>
#include <vector>

/* reminder
 * 1. I actually understand the meaning of the matrix wrong. It cannot be used like the connect island one.
 * 2. Dont forget to check if there's a connection or the connection has been used if(M[s][i] == 1)
 * */

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        side = M.size();
        int ret = 0;
        for (int i = 0; i < side; i++) {
            if (M[i][i] == 1) {
                ret += 1;
                dfs(M, i);
            }
        }
        return ret;
    }

    void dfs(vector<vector<int>>& M, int s) {
        if (M[s][s] != 1) return;
        M[s][s] = -1;
        for (int i = 0; i < side; i++) {
            if (M[s][i] == 1) {
                M[s][i] = -1;
                dfs(M, i);
            }
        }
    }
private:
    int side;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}