#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ababbababa = s
// aba = t
// 0 5 7

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 and s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j; 
    }
    return p;
}

int main() {
    string s, t;
    cin >> s >> t;
    // s = aba#ababbababa
    s = t + '#' + s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        if (p[i] == t.size()) {
            cout << i - 2 * t.size() << " ";
            // 6 11 13
            // 0 5 7
            // t.size() = 3
        }
    }
    return 0;
}

// k a bcd a bcl
// 1 5 3
// i1 = 1
// i2 = 5
// len = 3