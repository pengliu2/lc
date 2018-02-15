#include <iostream>
#include <vector>

using namespace std;

// TODO: generalize to k majorities

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() < 2) {
            return vector<int>(nums);
        }

        int a = 0;
        int b = 1;
        int cb = 0;
        int ca = 0;

        for (int n : nums) {
            if (n == a) {
                ca++;
            } else if (n == b) {
                cb++;
            } else if (ca == 0) {
                a = n;
                ca++;
            } else if (cb == 0) {
                b = n;
                cb++;
            } else {
                if (ca > 0) {
                    ca--;
                }
                if (cb > 0) {
                    cb--;
                }
            }
        }

        ca = 0;
        cb = 0;
        for (int n : nums) {
            if (a == n)
                ca++;
            else if (b == n)
                cb++;
        }

        vector<int>ret;
        if (ca > int(nums.size()/3))
            ret.push_back(a);
        if (cb > int(nums.size()/3))
            ret.push_back(b);
        return ret;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}