#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int d[2000][2000];
int a[2000];
int solve(int i, int j) {
    if (i == j) {
        return 1;
    } else if (i+1 == j) {
        if (a[i] == a[j]) {
            return 1;
        } else {
            return 0;
        }
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    if (a[i] != a[j]) {
        return d[i][j] = 0;
    } else {
        return d[i][j] = solve(i+1,j-1);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    memset(d,-1,sizeof(d));
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int a,b;
      cin >> a >> b;
      cout << solve(a-1,b-1) << '\n';
    }
    return 0;
}
