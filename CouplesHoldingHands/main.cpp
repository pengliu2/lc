#include <iostream>
#include <vector>
using namespace std;


/* reminder:
 * 1. union find not pos[i] = pos[i+1] but pos[row[i]] = pos[row[i+1]]
 * 2. must clear pos[pos[prev]] then pos[prev]
 * 3. don't forget the clear routes into and out from first node for each round
 * */
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> pos(row.size(), -1);

        for (int i = 0; i < row.size(); i += 2) {
            pos[row[i]] = row[i+1];
            pos[row[i+1]] = row[i];
        }

        int ret = 0;
        for (int i = 0; i < row.size(); i++) {
            int next = i;
            int couple = i % 2 == 0 ? i+1 : i-1;

            while ((pos[next] != -1) && (pos[next] != couple)) {
                ret +=1;
                int prev = next;
                next = pos[next] % 2 == 0 ? pos[next]+1 : pos[next]-1;
                pos[pos[prev]] = -1;
                pos[prev] = -1;
            }
            if (pos[next] != -1) {
                pos[pos[next]] = -1;
                pos[next] = -1;
            }
        }
        return ret;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}