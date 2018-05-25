#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows == 0) return 0;
        cols = matrix[0].size();
        if (cols == 0) return 0;

        int ans = 0;
        cache = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, helper(matrix, i, j));
            }
        }
        return ans;
    }
private:
    vector<vector<int>> cache;
    int rows;
    int cols;

    int helper(vector<vector<int>>& matrix, int row, int col) {
        if (cache[row][col] > 0) return cache[row][col];
        vector<int> d_r{-1, 0, 1, 0};
        vector<int> d_c{0, 1, 0, -1};

        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int r = row + d_r[i];
            int c = col + d_c[i];
            if (!inmatrix(r, c)) continue;
            if (matrix[r][c] <= matrix[row][col]) continue;
            ret = max(ret, helper(matrix, r, c));
        }
        cache[row][col] = ret + 1;
        return ret + 1;
    }

    bool inmatrix(int r, int c) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}