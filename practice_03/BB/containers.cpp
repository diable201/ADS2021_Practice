#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st[n + 1];
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (x != i) {
                ok = false;
            }
            st[i].push(x);
        }
    }

    if (ok) return 0;

    if (n == 2) {
        vector<string> res;
        while (!st[1].empty() and st[1].top() == 2) {
            st[1].pop();
            st[2].push(2);
            res.push_back("1 2");
        }
        while (!st[2].empty() and st[2].top() == 1) {
            st[2].pop();
            st[1].push(1);
            res.push_back("2 1");
        }
        while (!st[1].empty()) {
            if (st[1].top() != 1) {
                cout << 0 << '\n';
                return 0;
            } else {
                st[1].pop();
            }
        }
        while (!st[2].empty()) {
            if (st[2].top() != 2) {
                cout << 0 << '\n';
                return 0;
            } else {
                st[2].pop();
            }
        }
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << '\n';
        }
    } else {
        vector<pair<int, int> > res;
        for (int i = 2; i <= n; i++) {
            while (!st[i].empty()) {
                st[1].push(st[i].top());
                st[i].pop();
                res.push_back(make_pair(i, 1));
            }
        }
        while (!st[1].empty()) {
            int top = st[1].top();
            st[1].pop();
            if (top == 1) {
                st[3].push(top);
                res.push_back(make_pair(1, 3));
            } else {
                st[top].push(top);
                res.push_back(make_pair(1, top));
            }
        }
        while (!st[3].empty()) {
            int top = st[3].top();
            st[3].pop();
            if (top == 1) {
                st[1].push(1);
                res.push_back(make_pair(3, 1));
            } else {
                st[2].push(3);
                res.push_back(make_pair(3, 2));
            }
        }
        while (!st[2].empty() and st[2].top() == 3) {
            st[2].pop();
            res.push_back(make_pair(2, 3));
        }
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].first << " " << res[i].second << '\n';
        }
    }

    return 0;
}