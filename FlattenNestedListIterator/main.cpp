#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
         bool isInteger() const;

         // Return the single integer that this NestedInteger holds, if it holds a single integer
         // The result is undefined if this NestedInteger holds a nested list
         int getInteger() const;

         // Return the nested list that this NestedInteger holds, if it holds a nested list
         // The result is undefined if this NestedInteger holds a single integer
         const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
        index = 0;
    }

    int next() {
        index++;
        return l[index-1];
    }

    bool hasNext() {
        return index < l.size();
    }
private:
    int index;
    vector<int> l;
    void helper(const vector<NestedInteger>& nestedList) {
        for (const auto& n : nestedList) {
            if (n.isInteger()) {
                l.push_back(n.getInteger());
            } else {
                helper(n.getList());
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}