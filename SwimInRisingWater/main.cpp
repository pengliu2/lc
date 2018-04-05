#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. don't forget inner loop is cols, outer is rows
 */

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        ids = vector<vector<int>>(rows*cols, vector<int>{0, 0});
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ids[i * cols + j][0] = i * cols + j;
                ids[i * cols + j][1] = 1;
            }
        }
        int ret = 0;
        for (ret = 0; ret < rows * cols; ret++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    if (j > 0 && grid[j][k] == grid[j-1][k]) {
                        ids[j*cols + k][0] = unite(findparent(j*cols+k), findparent((j-1)*cols + k));
                    }
                    if (k > 0 && grid[j][k] == grid[j][k-1]) {
                        ids[j*cols + k][0] = unite(findparent(j*cols+k), findparent(j*cols + k -1));
                    }
                }
            }
            if (findparent(rows*cols-1) == findparent(0)) break;
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    grid[j][k] = max(grid[j][k], ret+1);
                }
            }
        }
        return ret;
    }
private:
    vector<vector<int>> ids;
    int findparent(int n) {
        if (ids[n][0] == n) return n;
        ids[n][0] = findparent(ids[n][0]);
        return ids[n][0];
    }

    int unite(int n1, int n2) {
        if (ids[n1][1] > ids[n2][1]) {
            ids[n2][0] = n1;
            return n1;
        } else if (ids[n1][1] < ids[n2][1]) {
            ids[n1][0] = n2;
            return n2;
        } else {
            ids[n1][0] = n2;
            ids[n1][1] += 1;
            return n2;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}