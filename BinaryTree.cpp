#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node * left;
    Node * right;
    int data;
    Node(int d) {
        left = 0;
        right = 0;
        data = d;
    }
};

class BinaryTree {
    private:
        Node * root = 0;
    int __size = 0;

    bool inner_find(int t, Node * current) {
        if (current == 0) {
            return false;
        } else if (current -> data == t) {
            return true;
        } else if (current -> data > t) {
            return inner_find(t, current -> left);
        } else {
            return inner_find(t, current -> right);
        }
    }

    Node * inner_insert(int t, Node * current) {
        if (current == 0) {
            __size++;
            return new Node(t);
        } else if (current -> data > t) {
            current -> left = inner_insert(t, current -> left);
        } else if (current -> data < t) {
            current -> right = inner_insert(t, current -> right);
        }
        return current;
    }

    void inner_traversal(Node * current, vector < int > & elements) {
        if (current == 0) {
            return;
        }
        inner_traversal(current -> left, elements);
        if (current -> left != 0 and current -> right == 0 or current -> left == 0 and current -> right != 0) {
            elements.push_back(current -> data);
        }
        inner_traversal(current -> right, elements);
    }

    public:
        BinaryTree() {}

    bool find(int t) {
        return inner_find(t, root);
    }

    void insert(int t) {
        root = inner_insert(t, root);
    }

    int size() {
        return __size;
    }

    vector < int > get_elements() {
        vector < int > elements;
        inner_traversal(root, elements);
        return elements;
    }
};

int main() {
    BinaryTree bt;
    
    return 0;
}
