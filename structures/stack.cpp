#include <iostream>

using namespace std;
struct Node {
    char data;
    Node * next;
};

class Stack {
    private:
        Node * tp = 0;
    int __size = 0;
    public:
        void push(char a) {
            Node * node = new Node();
            node -> data = a;
            node -> next = tp;
            tp = node;
            __size++;
        }

    void pop() {
        Node * node = tp;
        tp = tp -> next;
        delete node;
        __size--;
    }

    int size() {
        return __size;
    }

    bool empty() {
        return __size == 0;
    }

    void clear() {
        while (__size > 0) pop();
    }

    char top() {
        return tp -> data;
    }
};

int main() {
    Stack st;
    
    return 0;
}