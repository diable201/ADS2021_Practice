#include <bits/stdc++.h>
typedef long long ll;
#define MAX_INT 1e7

using namespace std;

int a[100][100];
int d[100][100];
int c[100][100];

void rec(int i, int j) {
    if (c[i][j] == -1) {
        cout << i + 1 << " " << j + 1 << '\n';
        return;
    }
    rec(i, c[i][j]);
    rec(c[i][j], j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--; y--;
        a[x][y] = l;
        a[y][x] = l;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 0)
                d[i][j] = a[i][j];
            else
                d[i][j] = MAX_INT;
            c[i][j] = -1;
        }
        d[i][i] = 0;
    }
            
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    c[i][j] = k;
                }

    cin >> x >> y;
    x--; y--;
    cout << d[x][y] << '\n';
    rec(x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
           cout << d[i][j] << " ";
        cout << '\n';
     }
                    
    return 0;
}
