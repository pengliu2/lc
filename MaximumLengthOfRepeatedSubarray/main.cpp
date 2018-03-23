#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. I think it too complicated: subarray in this problem is continuous
 *
 * 2. after comparing A[i~j] and B[m~n], cannot start from A[j+1] but still A[i+1]
 * */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        auto cache = vector<vector<int>>(A.size() + 1, vector<int>(B.size() + 1, 0));
        int ret = 0;
        for (int i = A.size()-1; i >= 0; i--) {
            for (int j = B.size()-1; j>= 0; j--) {
                cache[i][j] = A[i] == B[j] ? cache[i-1][j-1] + 1 : 0;
                ret = max(ret, cache[i][j]);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
