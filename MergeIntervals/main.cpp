#include <iostream>
#include <vector>
#include <limits>
#include <map>

using std::vector;
using std::map;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return vector<Interval>();
        auto min = std::numeric_limits<int>::max();
        auto max = std::numeric_limits<int>::min();

        for (const auto &i : intervals) {
            min = std::min(min, i.start);
            max = std::max(max, i.end);
        }
        vector<int> m(max + 1, -1);

        for (const auto &i : intervals) {
            auto len = i.end - i.start;
            m[i.start] = std::max(m[i.start], len);
        }

        vector<Interval> results;

        int i = min;
        while (i <= max) {
            if (m[i] < 0) {
                i += 1;
                continue;
            }
            Interval cur;
            cur.start = i;

            auto len = m[i];
            int j;
            for (j = i; j <= i+len; j++) {
                auto new_end = j + m[j];
                len = std::max(len, new_end - i);
            }
            cur.end = j-1;
            results.push_back(cur);
            i = j;
        }
        return results;
    }
};


int main() {
    Solution slt;
    vector<Interval> input;
//    input.push_back(Interval(1, 2));
//    input.push_back(Interval(3, 6));
//    input.push_back(Interval(4, 6));
    auto result = slt.merge(input);
    for (auto r : result) {
        std::cout << "[" << r.start << "," << r.end << "]";
    }
    return 0;
}