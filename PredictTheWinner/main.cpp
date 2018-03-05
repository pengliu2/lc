#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> cache(size);
        for (int i = 0; i < size; i++) {
            cache[i] = vector<int>{nums[i], 0};
        }
        for (int i = 1; i < size; i++) {
            for (int j = 0; j + i < size; j++) {
                int right_p1 = cache[j][1] + nums[j+i];
                int right_p2 = cache[j][0];
                int left_p1 = cache[j+1][1] + nums[j];
                int left_p2 = cache[j+1][0];
                if ((right_p1 - right_p2) >= (left_p1 - left_p2)) {
                    cache[j][0] = right_p1;
                    cache[j][1] = right_p2;
                } else {
                    cache[j][0] = left_p1;
                    cache[j][1] = left_p2;
                }
            }
        }
        return cache[0][0] >= cache[0][1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}