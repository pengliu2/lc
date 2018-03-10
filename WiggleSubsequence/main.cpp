#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        auto size = nums.size();
        if (size < 2) return size;
        int direction = 0;
        int ret = 1;
        for (auto i = 1; i < size; i++ ) {
            int newdirec = nums[i] - nums[i-1];
            if (newdirec > 0)
                newdirec = 1;
            else if (newdirec < 0)
                newdirec = -1;
            else {
                newdirec = direction;
                continue;
            }
            if (newdirec != direction) {
                ret += 1;
                direction = newdirec;
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}