#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0) return true;

        stack<char> s;
        auto str= preorder.c_str();
        int size = preorder.size();
        auto index = 0;
        do {
            if (str[index] != '#') {
                s.push(str[index]);
            } else {
                index += 2;
                if (index >= size)
                    break;
                if (str[index] == '#') {
                    if (s.empty()) break;
                    s.pop();
                } else {
                    s.push(str[index]);
                }
            }
            index += 2;
        } while (index < size && !s.empty());

        return index >= size && s.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}