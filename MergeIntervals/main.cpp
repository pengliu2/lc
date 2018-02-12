#include <iostream>
#include <vector>

using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}