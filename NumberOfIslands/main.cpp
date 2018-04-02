#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. only when left or upper cell is '1' shall we retrieve id from them
 * 2. don't forget to save current id to cache
 * 3. when cell == '0' continue
 * 4. min of upper and left might have already pointed to smaller id so still need to iterate all group id link to find the smallest one
 * 5. combine root is the key of union find
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;

        vector<int> groups;
        vector<vector<int>> cache(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0') continue;
                int id = -1;
                if (i > 0 && grid[i-1][j] == '1') {
                    id = findroot(groups, cache[i-1][j]);
                }
                if (j > 0 && grid[i][j-1] == '1') {
                    int left = findroot(groups, cache[i][j-1]);
                    if (id != -1 && id != left) {
                        groups[max(id, left)] = min(id, left);
                        id = min(id, left);
                    } else {
                        id = left;
                    }
                }
                if (id == -1) {
                    id = groups.size();
                    groups.push_back(id);
                }
                cache[i][j] = id;
            }
        }
        int ret = 0;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] == i) ret++;
        }
        return ret;
    }
    int findroot(vector<int> &groups, int node) {
        if (groups[node] == node)
            return node;
        return findroot(groups, groups[node]);
    }
};

class SolutionI {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<int> groups;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;
        vector<vector<int>> cache(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0') continue;
                int id = -1;
                if (i > 0 && grid[i-1][j] == '1') {
                    id = cache[i-1][j];
                }
                if (j > 0 && grid[i][j-1] == '1') {
                    int left = cache[i][j-1];
                    if (id != -1 && id != left) {
                        groups[max(id, left)] = min(id, left);
                        id = min(id, left);
                    } else {
                        id = left;
                    }
                }
                if (id == -1) {
                    id = groups.size();
                    groups.push_back(id);
                }
                cache[i][j] = groups[id];
            }
        }

        int ret = 0;
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i] == i) {
                ret++;
            }
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}