#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *even = head->next;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2 != nullptr && p2->next != nullptr) {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }
        p1->next = even;
        return head;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}