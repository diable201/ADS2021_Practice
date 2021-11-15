#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    string s;
    cin >> s; //abab
    set<string> a;
    for (int i = 0; i < s.size(); i++) { // i = 0
        string t = "";
        for (int j = i; j < s.size(); j++) { // j = i abab bab
            t += s[j];
            a.insert(t);
        }
    }
    cout << a.size() << endl;
    return 0;
}