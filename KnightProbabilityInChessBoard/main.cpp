#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. because the first inner loop is a trick to process outer cells then set them 0's
 * i need to be 1 larger than K, then break before reaches K+2
 * 2. when boad size is 1x2, or 1x2 or 2x2, piece cannot remain within board
 * 3. cannot directly use the number of out of boundary paths method, but to save possibilities for each cell
 * */
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        auto cache = vector<vector<vector<double>>>(K+1, vector<vector<double>>(N+4, vector<double>(N+4, 0.0)));
        r += 2;
        c += 2;
        cache[0][r][c] = 1.0;
        double ret = 1.0;

        for (int i = 1; i < K+2; i++) {
            double total = 0.0;
            double out = 0.0;

            for (int j = 0; j < N+4; j++) {
                for (int k = 0; k < N+4; k++) {
                    total += cache[i-1][j][k];
                    if (j < 2 || j > N+1 || k < 2 || k > N+1) {
                        out += cache[i-1][j][k];
                        cache[i-1][j][k] = 0.0;
                    }
                }
            }
            ret = ret * (total - out) / total;
            if (ret == 0.0) break;
            if (i == K+1) break;
            for (int j =  2; j < N+2; j++) {
                for (int k = 2; k < N+2; k++) {
                    if (cache[i-1][j][k] != 0) {
                        cache[i][j+2][k+1] += cache[i-1][j][k];
                        cache[i][j+2][k-1] += cache[i-1][j][k];
                        cache[i][j-2][k+1] += cache[i-1][j][k];
                        cache[i][j-2][k-1] += cache[i-1][j][k];

                        cache[i][j+1][k+2] += cache[i-1][j][k];
                        cache[i][j-1][k+2] += cache[i-1][j][k];
                        cache[i][j+1][k-2] += cache[i-1][j][k];
                        cache[i][j-1][k-2] += cache[i-1][j][k];
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}