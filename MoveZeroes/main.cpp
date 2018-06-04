#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                offset += 1;
                continue;
            }
            if (offset > 0) {
                nums[i - offset] = nums[i];
            }
        }

        for (int i = nums.size() - offset; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}