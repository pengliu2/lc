#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. must ask if the nodes in graph are all connected all can belong to sub-graphs
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        grouping = vector<int>(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].empty() || grouping[i] != -1) continue;
            if (group(graph, i, 0) == false) return false;
        }
        return true;
    }

    bool group(vector<vector<int>> &graph, int current, int grp) {
        if (grouping[current] != -1) {
            if (grouping[current] == grp) return true;
            else return false;
        }

        grouping[current] = grp;
        for (const auto &g : graph[current]) {
            if (group(graph, g, grp == 0 ? 1 : 0) == false)
                return false;
        }
        return true;
    }

private:
    vector<int> grouping;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}