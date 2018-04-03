#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        parents = vector<int>(edges.size() + 1);
        for (int i = 0; i < parents.size(); i++) parents[i] = i;
        for (const auto &e : edges) {
            int p1 = find(e[0]);
            int p2 = find(e[1]);
            if (p1 == p2) return e;
            parents[p2] = p1;
        }
        return vector<int>(2);
    }
    int find(int node) {
        if (parents[node] == node) return node;
        parents[node] =  find(parents[node]);
        return parents[node];
    }
private:
    vector<int>parents;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}