#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    set<string> a;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string w = "";
        for (int j = i; j < s.size(); j++) {
            w += s[j];
            a.insert(w);
        }
    }
    cout << a.size() << '\n';
    return 0;
}

// O(n^2 * log(m) * L)
// O(n^3 * log(m))