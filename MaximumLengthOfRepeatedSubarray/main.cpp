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
        auto iB = vector<int>(100, 0);
        for (int i = 0; i < B.size(); i++) {
            iB[B[i]] = 1;
        }
        int ret = 0;
        for (int i = 0; i + ret < A.size(); i++) {
            if (iB[A[i]]==0) {
                continue;
            }
            for (int j = 0; j + ret < B.size(); j++) {
                if (B[j] != A[i]) continue;
                int len = 0;
                int m = i;
                for (int k = j; k < B.size() && m < A.size(); k++,m++) {
                    if (B[k] != A[m]) break;
                    len += 1;
                }
                ret = max(ret, len);
            }
        }

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
