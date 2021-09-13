#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool is_valid(string s) {
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '{' or s[i] == '[' or s[i] == '(')
            st.push(s[i]);
        // {
        // [  }
        // {}
        // ()
        // ({   )}
        // ({  })
        else {
            if (st.empty())
                return false;
            if (s[i] == '}' and st.top() != '{')
                return false;
            if (s[i] == ']' and st.top() != '[')
                return false;
            if (s[i] == ')' and st.top() != '(')
                return false;
            st.pop();
        }
    }
    return (st.empty());
}

int main() {
    string s;
    cin >> s;
    if (is_valid(s)) cout << "yes\n";
    else cout << "no\n";
    return 0;
}