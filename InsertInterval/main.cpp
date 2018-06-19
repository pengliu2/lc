#include <iostream>
#include <vector>

using namespace std;

/*
 * reminders:
 * 1. intervals before new one
 * 2. intervals after new one
 * 3. interval include new one: dont add both to answer
 * 4. intervals inclued in new one
 * 5. intervals overlapped wit new one
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int start = newInterval.start;
        int end = newInterval.end;

        auto iter = intervals.begin();
        for (; iter != intervals.end(); iter++) {
            if (iter->start > end) {
                break;
            }
            if (iter->start <= start && iter->end >= end) {
                start = iter->start;
                end = iter->end;
                iter++;
                break;
            }
            if (iter->start > start && iter->end < end) {
                continue;
            }
            if (iter->end < start) {
                ans.push_back(*iter);
                continue;
            }
            start = min(iter->start, start);
            end = max(iter->end, end);
        }

        ans.push_back(Interval(start, end));

        for (; iter != intervals.end(); iter++) {
            ans.push_back(*iter);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}