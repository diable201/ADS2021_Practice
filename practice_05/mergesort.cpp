#include <bits/stdc++.h>

using namespace std;
int n;
int a[10000000];

void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while (uk1 < n1 && uk2 < n2) {
        if (L[uk1] <= R[uk2]) {
            a[k] = L[uk1];
            uk1++;
        } else {
            a[k] = R[uk2];
            uk2++;
        }
         k++;
    }

    while (uk1 < n1) {
        a[k] = L[uk1];
        uk1++;
        k++;
    }

    while (uk2 < n2) {
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //sort(a, a + n) // quicksort
    //quicksort(0, n - 1);
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
    return 0;
}