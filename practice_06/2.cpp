#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(string s) {
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
    if (f(s) == f(t))
        cout << "YES\n";
    else
        cout << "NO\n";
}