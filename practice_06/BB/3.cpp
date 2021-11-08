#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// ababababab
// 0012345678

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
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < s.size(); i++) {
        cout << p[i] << " ";
    }
    return 0;
}