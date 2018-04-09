#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. must figure out the rules: I didn't realize that once one cell is flipped, 9 adjacent ones should be flipped, not just 6
 * 2. to define a bool inboard(int row, int col) could make code more clear
 */

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> ret = board;
        rows = board.size();
        if (rows == 0) return ret;
        cols = board[0].size();
        if (cols == 0) return ret;

        if (board[click[0]][click[1]] == 'M') {
            ret[click[0]][click[1]] = 'X';
            return ret;
        }

        dfs(board, click[0], click[1], ret);
        return ret;
    }
private:
    int rows;
    int cols;

    void dfs(vector<vector<char>> &board, int r, int c, vector<vector<char>> &ret) {
        if (board[r][c] == 'B' || board[r][c] == 'M') return;
        ret[r][c] = 'B';
        board[r][c] = 'B';
        int bombs = 0;
        bool conti = check(board, r, c, &bombs);
        if (bombs != 0) {
            ret[r][c] = '0' + bombs;
            return;
        }

        if (r > 0) {
            dfs(board, r-1, c, ret);
            if (c > 0) {
                dfs(board, r-1, c-1, ret);
            }
            if (c < cols - 1) {
                dfs(board, r-1, c+1, ret);
            }
        }
        if (r < rows - 1) {
            dfs(board, r+1, c, ret);
            if (c > 0) {
                dfs(board, r+1, c-1, ret);
            }
            if (c < cols - 1) {
                dfs(board, r+1, c+1, ret);
            }
        }
        if (c > 0) {
            dfs(board, r, c-1, ret);
        }
        if (c < cols - 1) {
            dfs(board, r, c+1, ret);
        }
        return;
    }

    int check(vector<vector<char>> &board, int r, int c, int *bombs) {
        int ret = 0;
        int conti = true;
        if (r > 0) {
            if (board[r-1][c] == 'M') {
                ret += 1;
                conti = false;
            }
            if (c > 0) {
                if (board[r-1][c-1] == 'M')
                    ret += 1;
            }
            if (c < cols-1) {
                if (board[r-1][c+1] == 'M')
                    ret += 1;
            }
        }
        if (r < rows-1) {
            if (board[r+1][c] == 'M') {
                ret += 1;
                conti = false;
            }
            if (c > 0) {
                if (board[r+1][c-1] == 'M')
                    ret += 1;
            }
            if (c < cols - 1) {
                if (board[r+1][c+1] == 'M')
                    ret += 1;
            }
        }
        if (c > 0 && board[r][c-1] == 'M') {
            ret += 1;
            conti = false;
        }
        if (c < cols - 1 && board[r][c+1] == 'M') {
            ret += 1;
            conti = false;
        }

        *bombs = ret;
        return conti;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}