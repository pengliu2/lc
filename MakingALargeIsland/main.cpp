#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. if using 1-d parent group cache, don't forget to initialize groups as rol * cols + col
 * 2. when trying each 0, only check neighbor that is 1
 * 3. check row and col: r >=0 && r < rols && c >=0 && c < cols
 * 4. union find: union should check if 2 nodes have aleady connected before union them
 * 5. be very careful for union find height reduction union
 */

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        if (rows == 0) return 0;
        cols = grid[0].size();
        if (cols == 0) return 0;

        groups = vector<vector<int>>(rows * cols, vector<int>{-1, 0, 0});
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                int g = i * cols + j;
                groups[g][0] = g;
                groups[g][1] = 1;
                groups[g][2] = 1;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                if (i > 0 && (grid[i-1][j] == 1)) {
                    join(i * cols + j, (i-1)*cols + j);
                }
                if (j > 0 && (grid[i][j-1] == 1)) {
                    join(i*cols + j, i * cols + j - 1);
                }
            }
        }

        int ret = 0;
        vector<int> v_r{-1, 0, +1, 0};
        vector<int> v_c{0, -1, 0, +1};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) continue;
                vector<int> f;
                int s = 1;
                for (int k = 0; k < 4; k++) {
                    int r = i+v_r[k];
                    int c = j+v_c[k];
                    if (in_grid(r, c) && (grid[r][c] == 1)) {
                        int p = find(r * cols + c);
                        if (!in_vector(p, f)) {
                            s += groups[p][2];
                            f.push_back(p);
                        }
                    }
                }
                ret = max(ret, s);
            }
        }
        if (ret == 0)
            return rows * cols;
        else
            return ret;
    }

private:
    vector<vector<int>> groups;
    int rows;
    int cols;

    bool in_vector(int i, vector<int> &v) {
        for (int j : v) {
            if (i == j) return true;
        }
        return false;
    }
    bool in_grid(int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    int find(int node) {
        if (groups[node][0] == node)
            return node;
        int ret = find(groups[node][0]);
        groups[node][0] = ret;
        return ret;
    }

    int join(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if (p1 == p2) return p1;
        int ret;
        if (groups[p1][1] > groups[p2][1]) {
            groups[p2][0] = p1;
            groups[p1][2] += groups[p2][2];
            ret = p1;
        } else if (groups[p2][1] > groups[p1][1]) {
            groups[p1][0] = p2;
            groups[p2][2] += groups[p1][2];
            ret = p2;
        } else {
            groups[p1][0] = p2;
            groups[p2][1] += 1;
            groups[p2][2] += groups[p1][2];
            ret = p2;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}