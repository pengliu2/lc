#include <iostream>
#include <vector>

using namespace std;

class NumArray {

public:
    vector<int> n;
    vector< vector<int> > sums;
    vector< vector<bool> > valid;
    vector<int> n2;

    NumArray(std::vector<int> nums) : n(nums){
        int len = n.size();
        sums.resize(len);
        valid.resize(len);
        n2.resize(len);
        for (int i=0; i < len; i++) {
            sums[i] = vector<int>(len);
            sums[i][i] = n[i];
            valid[i] = vector<bool>(len, false);
            valid[i][i] = true;

        }
    }

    void update(int i, int val) {
        int diff = val - n[i];
        n[i] = val;
        int len = n.size();
        for (int k=0; k <= i; k++) {
            for (int j=i; j < len; j++) {
                if (valid[k][j]) {
                    sums[k][j] += diff;
                }
            }
        }
    }

    int sumRange(int i, int j) {
        if (valid[i][j])
            return sums[i][j];

        int sum = n[i];
        for (int k=i+1; k<=j; k++){
            if (valid[k][j]) {
                sums[i][j] = sum + sums[k][j];
                valid[i][j] = true;
                return sums[i][j];
            }
            sum += n[k];
            sums[i][k] = sum;
            valid[i][k] = true;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
int main() {
    vector<int> v{1,3,5};
    NumArray n(v);
    cout << n.n[0] << "," << n.n[1] << "," << n.n[2] << endl;
    return 0;
}