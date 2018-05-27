#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. what if node has edge pointing to itself? false?
 * 2. what if nodes are separate into several sub-graphs? Okay
 * 3. is there a chance that pointing to unsafe doesn't mean unsafe?
 * 4. is there a chance that pointing to safe doesn't mean safe?
 */

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        cache = vector<int>(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (check(graph, i)) ans.push_back(i);
        }
        return ans;
    }
private:
    vector<int> cache;

    bool check(vector<vector<int>>& graph, int node) {
        if (cache[node] != 0) return cache[node] == 1;
        cache[node] = -2;
        for (const auto n : graph[node]) {
            if (check(graph, n) == false) {
                cache[node] = -1;
                return false;
            }
        }
        cache[node] = 1;
        return true;
    }
};

class SolutionI {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;
        safe = vector<int>(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(graph, i)) {
                ret.push_back(i);
            }
        }

        return ret;
    }

    private:
    vector<int> safe;
    bool dfs(vector<vector<int>> &graph, int cur) {
        if (safe[cur] == 1) return true;
        if (safe[cur] == -1) return false;
        if (safe[cur] == -2) return false;
        if (graph[cur].empty()) return true;

        safe[cur] = -2;
        for (const int g : graph[cur]) {
            if (dfs(graph, g) == false) {
                safe[cur] = -1;
                return false;
            }
        }
        safe[cur] = 1;
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}