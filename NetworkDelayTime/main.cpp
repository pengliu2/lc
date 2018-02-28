#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> nodes(N, INT_MAX);
        nodes[K-1] = 0;
        map<int, map<int, int>> m;
        for (auto t : times) {
            if (m.count(t[0] - 1) == 0) {
                m[t[0]-1] = map<int, int>();
            }
            m[t[0]-1][t[1]-1] = t[2];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                auto p = m[j];
                auto delay = nodes[j];
                if (delay == INT_MAX) continue;
                for (auto q : p) {
                    nodes[q.first] = min(nodes[q.first], delay + q.second);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret = max(nodes[i], ret);
        }

        if (ret == INT_MAX)
            return -1;
        else
            return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}