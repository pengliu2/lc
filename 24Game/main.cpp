#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SolutionI {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<int> cache = vector<int>(4, 0);
        for (int i = 0; i < nums.size(); i++) {
            cache[i] = 1;
            if (helper(nums, cache, 1, nums[i])) return true;
            cache[i] = 0;
        }
        return false;
    }
private:
    bool helper(vector<int>& nums, vector<int> &cache, int used, float value) {
        if (used == 4) {
            if (abs(value - 24) < 0.0001) return true;
            else return false;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (cache[i] == 1) continue;
            cache[i] = 1;
            vector<float> values = compute(value, nums[i]);
            for (const auto v : values) {
                if (helper(nums, cache, used + 1, v)) {
                    cout << "loop: " << value << ", " << nums[i] << endl;
                    return true;
                }
            }
            cache[i] = 0;
        }

        if (used == 2) {
            int r[2];
            int j = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (cache[i] == 0) {
                    r[j] = nums[i];
                    if (++j == 2) break;
                }
            }

            vector<float> values = compute(r[0], r[1]);
            for (const auto v : values) {
                vector<float> final = compute(value, v);
                for (const auto k : final) {
                    if (abs(k - 24) < 0.0001) {
                        cout << "2x2: " << value << ", " << r[0] << ", " << r[1] << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    vector<float> compute(float a, float b) {
        vector<float> ret;

        ret.push_back(a+b);
        ret.push_back(a-b);
        ret.push_back(b-a);
        ret.push_back(b*a);
        if (a != 0)
            ret.push_back(b/a);
        if (b != 0)
            ret.push_back(a/b);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}