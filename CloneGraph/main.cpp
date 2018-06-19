#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return node;
        map<int, UndirectedGraphNode*> visited;
        return clone(node, visited);
    }
private:
    UndirectedGraphNode* clone(UndirectedGraphNode* node, map<int, UndirectedGraphNode*> &visited) {
        UndirectedGraphNode* ans = new UndirectedGraphNode(node->label);
        visited[node->label] = ans;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (node->neighbors[i] == node) {
                ans->neighbors.push_back(ans);
                continue;
            }
            if (visited.count(node->neighbors[i]->label)) {
                ans->neighbors.push_back(visited[node->neighbors[i]->label]);
                continue;
            }
            ans->neighbors.push_back(clone(node->neighbors[i], visited));
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}