#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. must ask if the nodes in graph are all connected all can belong to sub-graphs
 * 2. don't forget when node is grouped and group is correct, return true
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> grouping = vector<int>(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (grouping[i] != 0) continue;
            if (helper(graph, i, grouping, 1) == false) return false;
        }
        return true;
    }

    bool helper(vector<vector<int>>& graph, int node, vector<int>& grouping, int group) {
        if (grouping[node] != 0 && grouping[node] != group) return false;
        grouping[node] = group;
        for(const auto v :graph[node]) {
            if (helper(graph, v, grouping, -group) == false) return false;
        }
        return true;
    }
};

class SolutionI {
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