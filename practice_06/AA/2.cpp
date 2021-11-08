#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// s, t
// s (n = s.size()) == t (m = t.size())
// O(max(n, m))
// n1 == n2 O(1)

ll hash_(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] * p_pow;
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s, t;
    cin >> s >> t;
    if (hash_(s) == hash_(t))
        cout << "Equal\n";
    else 
        cout << "Not Equal\n";
}