#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. 2-D parent pointers size is rows*cols, not rows*cols-1
 * 2. when iterating node, always ignore 0 nodes (I forgot that in SolutionI, last for loop
 * 3. when a brick falls, it turns 0 too in grid!!!
 * 4. SolutionI is TLE
 * 5. SolutionII is TLE
 * 6. when uniting 2 same numbers, don't do anything!!! or counting would be wrong
 */
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> ret;
        ids = vector<vector<int>>(rows * cols, vector<int>(2, 0));
        vector<vector<int>> origin(rows, vector<int>(cols, 0));
        for (const vector<int> &h : hits) {
            origin[h[0]][h[1]] = grid[h[0]][h[1]];
            grid[h[0]][h[1]] = 0;
        }
        cout << "1" << endl;
        for (int i = 0; i < cols; i++) {
            if (grid[0][i] == 0) continue;
            ids[i][0] = 0;
            ids[i][1] = 0;
        }
        cout << "2" << endl;
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << i << "," << j << endl;
                if (grid[i][j] == 0) continue;
                cout << 1 << endl;
                ids[i * cols + j][0] = i * cols + j;
                ids[i * cols + j][1] = 1;
                cout << 2 << endl;
                if (grid[i - 1][j] == 1) {
                    cout << 3 << endl;
                    unite(findp((i - 1) * cols + j), findp(i * cols + j));
                }

                if (j > 0 && grid[i][j - 1] == 1) {
                    unite(findp(i * cols + j - 1), findp(i * cols + j));
                }
            }
        }
        cout << "3" << endl;
        int debug = 0;
        vector<int> rets(hits.size(), 0);
        for (int k = hits.size() - 1; k >= 0; k--) {
            const vector<int> &h = hits[k];
            if (origin[h[0]][h[1]] == 0) continue;

            grid[h[0]][h[1]] = 1;
            ids[h[0] * cols + h[1]][0] = h[0] == 0 ? 0 : h[0]*cols + h[1];
            ids[h[0] * cols + h[1]][1] = 1;
            int ret = 0;
            int new_p = h[0] * cols + h[1];
            if (h[0] == 0) ids[h[1]][0] = 0;

            if (h[0] > 0 && grid[h[0] - 1][h[1]] == 1) {
                int p1 = findp((h[0]-1)*cols + h[1]);
                if (p1 > 0) ret += ids[p1][1];
                new_p = unite(new_p, p1);
            }
            if (h[0] < rows - 1 && grid[h[0] + 1][h[1]] == 1) {
                int p2 = findp((h[0]+1)*cols + h[1]);
                if (p2 > 0) ret += ids[p2][1];
                new_p = unite(new_p, p2);
            }
            if (h[1] > 0 && grid[h[0]][h[1] - 1] == 1) {
                int p3 = findp(h[0]*cols + h[1] - 1);
                if (p3 > 0) ret += ids[p3][1];
                new_p = unite(new_p, p3);
            }
            if (h[1] < cols - 1 && grid[h[0]][h[1] + 1] == 1) {
                int p4 = findp(h[0]* cols + h[1] + 1);
                if (p4 > 0) ret += ids[p4][1];
                new_p = unite(new_p, p4);
            }
            if (new_p == 0)
                rets[k] = ret;

            grid[h[0]][h[1]] = 1;
            cout << debug++ << endl;
        }
        return rets;
    }

private:
    vector<vector<int>> ids;

    int findp(int n) {
        if (ids[n][0] == n) return n;
        ids[n][0] = findp(ids[n][0]);
        return ids[n][0];
    }

    int unite(int n1, int n2) {
        ids[max(n1, n2)][0] = min(n1, n2);
        ids[min(n1, n2)][1] += ids[max(n1, n2)][1];
        return min(n1, n2);
    }
};

class SolutionII {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> ret;
        ids = vector<int>(rows * cols, -1);

        for (int i = 0; i < cols; i++) {
            if (grid[0][i] == 0) continue;
            ids[i] = i;
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                ids[i*cols + j] = i*cols + j;
            }
        }

        for (const vector<int> &h : hits) {
            if (grid[h[0]][h[1]] == 0) {
                ret.push_back(0);
                continue;
            }

            grid[h[0]][h[1]] = 0;

            for (int i = h[0]; i < rows; i++) {
                for (int j = h[1]; j < cols; j++) {
                    if (grid[i][j] == 0) continue;
                    ids[i*cols + j] = i*cols + j;

                    if (grid[i-1][j] == 1) {
                        unite(findp((i-1) * cols + j), findp(i*cols + j));
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        unite(findp(i*cols + j - 1), findp(i*cols + j));
                    }
                }
            }
            int falls = 0;
            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 0) continue;
                    if (findp(i*cols + j) >= cols) {
                        falls++;
                        grid[i][j] = 0;
                    }

                }
            }
            ret.push_back(falls);
        }
        return ret;
    }

private:
    vector<int> ids;
    int findp(int n) {
        if (ids[n] == n) return n;
        ids[n] = findp(ids[n]);
        return ids[n];
    }

    int unite(int n1, int n2) {
        if (n1 == n2) return n1;
        ids[max(n1, n2)] = min(n1, n2);
        return min(n1, n2);
    }
};

class SolutionI {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> ret;
        ids = vector<int>(rows * cols, -1);
        for (const vector<int> &h : hits) {
            if (grid[h[0]][h[1]] == 0) {
                ret.push_back(0);
                continue;
            }

            grid[h[0]][h[1]] = 0;
            for (int i = 0; i < cols; i++) {
                if (grid[0][i] == 0) continue;
                ids[i] = i;
            }
            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 0) continue;
                    ids[i*cols + j] = i*cols + j;

                    if (grid[i-1][j] == 1) {
                        unite(findp((i-1) * cols + j), findp(i*cols + j));
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        unite(findp(i*cols + j - 1), findp(i*cols + j));
                    }
                }
            }
            int falls = 0;
            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 0) continue;
                    if (findp(i*cols + j) >= cols) {
                        falls++;
                        grid[i][j] = 0;
                    }

                }
            }
            ret.push_back(falls);
        }
        return ret;
    }

private:
    vector<int> ids;
    int findp(int n) {
        if (ids[n] == n) return n;
        ids[n] = findp(ids[n]);
        return ids[n];
    }

    int unite(int n1, int n2) {
        ids[max(n1, n2)] = min(n1, n2);
        return min(n1, n2);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}