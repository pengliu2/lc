#include <iostream>
#include <vector>

/*
 * reminder:
 * 1. not so straightforward: when new color == old color, must not do anything, or deadloop
 */

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        cols = image[0].size();
        int oldcolor = image[sr][sc];
        if (oldcolor != newColor)
            dfs(image, sr, sc, oldcolor, newColor);
        return image;
    }
private:
    void dfs(vector<vector<int>> &image, int r, int c, int old, int color) {
        if (in_image(r, c) && image[r][c] == old)
            image[r][c] = color;
        else
            return;
        dfs(image, r+1, c, old, color);
        dfs(image, r-1, c, old, color);
        dfs(image, r, c-1, old, color);
        dfs(image, r, c+1, old, color);
    }
    bool in_image(int r, int c) {
        return (r >= 0 && r < rows && c >=0 && c < cols);
    }
    int rows;
    int cols;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}