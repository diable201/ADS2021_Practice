#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 10;
int n, m;
// 26 abcdef...
// 10 1-9

class Node {
    public:
    char value;
    Node *ch[MAXN];
    string city;
    Node(char value, string city) {
        this->value = value;
        this->city = city;
        for (int i = 0; i < MAXN; i++)
            ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;
    int m;
    Trie(int m) {
        this->m = m;
        root = new Node(' ', " ");
    }

    void insert(string s, string sity) {

    }

    void search(Node *node, string s, int cnt = 0) {
        
    }

};