#include <iostream>
#include <vector>

/*
 * reminder:
 * 1. union find must check if n1 == n2 when unite, or count of nodes could be wrong
 */

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        rows = grid.size();
        cols = grid[0].size();

        int ret = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    ret = max(ret, dfs(grid, i, j));
                    if (ret >= cols*rows) return ret;
                }
            }
        }

        return ret;
    }

private:
    int dfs(vector<vector<int>> &grid, int r, int c) {
        int ret = 1;
        grid[r][c] = 0;
        if (r > 0 && grid[r-1][c] == 1) {
            ret += dfs(grid, r-1, c);
        }
        if (r < rows - 1 && grid[r+1][c] == 1) {
            ret += dfs(grid, r+1, c);
        }
        if (c > 0 && grid[r][c-1] == 1) {
            ret += dfs(grid, r, c-1);
        }
        if (c < cols - 1 && grid[r][c+1] == 1) {
            ret += dfs(grid, r, c+1);
        }
        return ret;
    }

    int cols;
    int rows;
};

class SolutionI {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        parents = vector<vector<int>>(rows*cols, vector<int>{-1, 1, 0});
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                parents[i*cols + j][0] = i*cols + j;
                parents[i*cols + j][1] = 1;
                parents[i*cols + j][2] = 1;
                if (i > 0 && grid[i-1][j] == 1) {
                    unite(i*cols+j, findp((i-1)*cols + j));
                }
                if (j > 0 && grid[i][j-1] == 1) {
                    unite(findp(i*cols+j), findp(i*cols + j -1));
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < cols*rows; i++) {
            ret = max(parents[i][2], ret);
        }

        return ret;
    }

private:
    vector<vector<int>> parents;
    int findp(int node) {
        if (parents[node][0] == node) return node;
        parents[node][0] = findp(parents[node][0]);
        return parents[node][0];
    }

    int unite(int n1, int n2) {
        if (n1 == n2) return n1;
        if (parents[n1][1] > parents[n2][1]) {
            parents[n2][0] = n1;
            parents[n1][2] += parents[n2][2];
            return n1;
        }
        if (parents[n1][1] < parents[n2][1]) {
            parents[n1][0] = n2;
            parents[n2][2] += parents[n1][2];
            return n2;
        }
        parents[n2][0] = n1;
        parents[n1][1] += 1;
        parents[n1][2] += parents[n2][2];
        return n1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}