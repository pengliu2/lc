#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1=0;
        int p2=0;

        do {
            p1 = nums[p1];
            p2 = nums[p2];
            p2 = nums[p2];
        } while (p1 != p2);

        p2 = 0;
        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}