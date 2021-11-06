#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// abcd = s
// bcda cdab dabc abcd
// bcda = t

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
    // abcd = s
    // bcda = t
    // s = bcda#abcdabcd
    s = t + '#' + s + s;
    vector<int> p = prefix_function(s);
    bool ok = false;
    for (int i = 0; i < s.size(); i++) {
        if (p[i] == t.size()) {
            ok = true;
            break;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}