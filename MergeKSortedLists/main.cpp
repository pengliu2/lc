#include <iostream>
#include <vector>
#include <set>
#include <iostream>

/*
 * reminder:
 * 1. set only keep 1 copy of same order data
 * 2. set uses comparator to decide if two elements are identicle
 * 3. don't forget to update moving pointers: for input and answer
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<ListNode*> pointers;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pointers.push_back(lists[i]);
            }
        }

        auto findleast = [](const ListNode* a, const ListNode* b) ->bool {
            return a != nullptr && b != nullptr && a->val < b->val;
        };

        multiset<ListNode*, decltype(findleast)> q(findleast);
        for (int i = 0; i < pointers.size(); i++) {
            if (pointers[i] != nullptr)
                q.insert(pointers[i]);
        }


        ListNode* ans = new ListNode(0);
        ListNode* p = ans;

        while (!q.empty()) {
            ListNode *first = *q.begin();
            p->next = new ListNode(first->val);
            p = p->next;
            q.erase(q.begin());
            if (first != nullptr){
                first = first->next; {
                    if (first != nullptr) {
                        q.insert(first);
                    }
                }
            }
        }

        return ans->next;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}