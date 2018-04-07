#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. decide a special value for special nodes. In this case, nodes on edges can have a parent 0. Thus, 0 must need
 * special treatment in find
 */

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows < 1) return;
        int cols = board[0].size();
        if (rows < 3 || cols < 3) return;

        parents = vector<vector<int>>(rows * cols, vector<int>{-1, 0});

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'X')
                    continue;

                int index = i * cols + j;
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                    parents[i * cols + j][0] = 0;
                else {
                    parents[i * cols + j][0] = i * cols + j;
                }
                parents[i * cols + j][1] = 1;

                if (i > 0 && board[(i-1)][j] == 'O') {
                    parents[index][0] = unite(findp(index), findp((i-1)*cols + j));
                }
                if (j > 0 && board[i][j-1] == 'O') {
                    parents[index][0] = unite(findp(index), findp(i*cols + j -1));
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && findp(i*cols + j) != 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    vector<vector<int>> parents;
    int findp(int n) {
        if (n == 0) return 0;
        if (parents[n][0] == n) return n;
        parents[n][0] = findp(parents[n][0]);
        return parents[n][0];
    }

    int unite(int n1, int n2) {
        if (n1 == n2) return n1;
        if (min(n1, n2) == 0) {
            parents[max(n1, n2)][0] = 0;
            return 0;
        }
        if (parents[n1][1] > parents[n2][1]) {
            parents[n2][0] = n1;
            return n1;
        } else if (parents[n2][1] > parents[n1][1]) {
            parents[n1][0] = n2;
            return n2;
        } else {
            parents[n1][0] = n2;
            parents[n2][1] += 1;
            return n2;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}