#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * reminder:
 * 1. don't forget inner loop is cols, outer is rows
 * 2. because numbers in matrix are 0..cols*rows-1, we can just memorize their positions and only check 1 number per loop
 * 3. we can also not update numbers in grid. At time t, any numbers smaller than t can be connected.
 * 4. if search is used, this problem is a one that fits Dijkstra algorithm, bfs based
 * BinarySearchAndDFS:
 * 5. someone implemented DFS using a trick that highest t <= N*N-1, using binary seach to check where's least working t
 * 6. I implemented that DFS based algorithm. Trick is once node is visited, don't visit again for a validation, or TLE
 * 7. so we must maintain another matrix, used.
 */
class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
    }
};

class SolutionBinarySearchAndDFS {
public:
    int swimInWater(vector<vector<int>> &grid) {
        row = grid.size();
        col = grid[0].size();
        int mint = grid[row-1][col-1];
        int maxt = row * col - 1;
        while (mint < maxt) {
            int mid = mint + (maxt - mint)/2;
            vector<vector<int>> used(row, vector<int>(col, 0));
            if (validate(grid, mid, used)) {
                maxt = mid;
            } else {
                mint = mid + 1;
            }
        }
        return maxt;
    }

    bool validate(vector<vector<int>> &grid, int t, vector<vector<int>> &used) {
        return helper(grid, 0, 0, t, used);
    }

    bool helper(vector<vector<int>> &grid, int r, int c, int t, vector<vector<int>> &used) {
        if (r == row -1 && c == col - 1 ) {
            return true;
        }
        if (!inGrid(r, c)) return false;
        if (used[r][c] == 1) return false;
        if (grid[r][c] > t) return false;

        used[r][c] = 1;
        if (helper(grid, r+1, c, t, used)) {
            return true;
        }
        if (helper(grid, r, c+1, t, used)) {
            return true;
        }

        if (helper(grid, r-1, c, t, used)) {
            return true;
        }
        if (helper(grid, r, c-1, t, used)) {
            return true;
        }
        return false;
    }

    bool inGrid(int r, int c) {
        if (r >= row) return false;
        if (c >= col) return false;
        if (r < 0) return false;
        if (c < 0) return false;
        return true;
    }
private:
    int row;
    int col;
};

class SolutionUnionFind {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        ids = vector<vector<int>>(rows*cols, vector<int>{0, 0});
        vector<int> pos(rows*cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ids[i * cols + j][0] = i * cols + j;
                ids[i * cols + j][1] = 1;
                pos[grid[i][j]] = i*cols + j;
            }
        }
        int ret = 0;
        for (ret = 0; ret < rows * cols; ret++) {
            int r = pos[ret] / cols;
            int c = pos[ret] % cols;
            if (r > 0 && grid[r - 1][c] < grid[r][c])
                ids[r * cols + c][0] = unite(findparent((r - 1) * cols + c), findparent(r * cols + c));
            if (r < rows - 1 && grid[r + 1][c] < grid[r][c]) {
                ids[r * cols + c][0] = unite(findparent((r + 1) * cols + c), findparent(r * cols + c));
            }
            if (c > 0 && grid[r][c - 1] < grid[r][c])
                ids[r * cols + c][0] = unite(findparent(r * cols + c - 1), findparent(r * cols + c));
            if (c < cols - 1 && grid[r][c + 1] < grid[r][c])
                ids[r * cols + c][0] = unite(findparent(r * cols + c + 1), findparent(r * cols + c));

            if (findparent(rows * cols - 1) == findparent(0)) break;

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