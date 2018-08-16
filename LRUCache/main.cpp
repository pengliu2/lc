#include <iostream>
#include <map>

using namespace std;

struct MyListNode {
    int val;
    int key;
    MyListNode * prev;
    MyListNode * next;
    MyListNode(int k, int value) : key(k), val{value}, prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity) {
        c = capacity;
        size = 0;
        head = nullptr;
        last = nullptr;
    }

    int get(int key) {
        if (m.count(key) == 0) return -1;
        MyListNode* l = m[key];
        int ret = l->val;
        cout << "getting " << key << ":";
        prt();
        promote(l);
        return ret;
    }

    void put(int key, int value) {
        cout << "putting " << key << "=>" << value << ": ";
        if (m.count(key)) {
            m[key]->val = value;
            promote(m[key]);
            return;
        }
        if (size == 0) {
            head = new MyListNode(key, value);
            m[key] = head;
            return;
        }
        if (size < c) {
            MyListNode* t = new MyListNode(key, value);
            m[key] = t;
            head->prev = t;
            t->next = head;
            t->prev = nullptr;
            head = t;
            size++;
        } else {
            int l = last->key;
            last->key = key;
            last->val = value;
            m.erase(l);
            m[key] = last;
            promote(last);
        }
    }
private:
    void prt() {
        MyListNode *p = head;
        while (p != nullptr) {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << endl;
    }

    void prtm() {
        for (const auto i : m) {
            cout << i.first << "=>" << i.second << ", ";
        }
        cout << endl;
    }

    void promote(MyListNode* l) {
        cout << "promote: ";
        if (head == l) return;
        if (last == l) {
            last = l->prev;
            last->next = nullptr;
            l->next = head;
            l->prev = nullptr;
            head = l;
            return;
        }
        l->prev->next = l->next;
        l->next->prev = l->prev;
        l->next = head;
        l->prev = nullptr;
        head = l;
        prt();
        prtm();
    }
    map<int, MyListNode*> m;
    MyListNode *head;
    MyListNode *last;
    int c;
    int size = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}