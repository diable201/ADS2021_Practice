#include <iostream>
#include <vector>

using namespace std;

int find_lower(vector<int> &v, int x) { // max a[i] <= x
    int l = -1;
    int r = (int)v.size();
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (v[m] <= x)
            l = m;
        else 
            r = m;
    }
    return l;
}

bool find(vector<int> &a, int x) {
    int i = find_lower(a, x);
    return i >= 0 and a[i] == x;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (k--) {
        int x;
        cin >> x;
        if (find(v ,x))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}