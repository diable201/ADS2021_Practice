#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// abc
// hash(abc) = a * p^0 + b * p^1 + c * p^2
// p = 'a' .... 'z' = 31


ll hash_(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += (s[i] - 'a' + 1) * p_pow;
        // sum += s[i] * p_pow;
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << hash_(s) << endl;
    return 0;
}