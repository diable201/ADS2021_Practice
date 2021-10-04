#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->right == NULL and node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
        return node;
    }

    int depth(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << '\n';
        inOrder(node->right);
    }
};

int main() {
    BST *bst = new BST();
    int n;
    while (cin >> n) {
        if (n == 0) break;
        else bst->root = bst->insert(bst->root, n);
    }
    cout << bst->depth(bst->root) << '\n';
    return 0;
}