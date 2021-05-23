#include <bits/stdc++.h>

using namespace std;

char grid[400][400];

void solve() {
    int n;
    cin >> n;
    int i1=-1,j1=-1,i2=-1,j2=-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j]=='*') {
                if (i1==-1) {
                    i1=i;
                    j1=j;
                } else {
                    i2=i;
                    j2=j;
                }
            }
        }
    }
    if (i1==i2) {
        if (i1>0) {
            grid[i1-1][j1]=grid[i2-1][j2]='*';
        } else {
            grid[i1+1][j1]=grid[i2+1][j2]='*';
        }
    } else if (i2 > i1) {
        if (j2 != j1) {
            grid[i2][j1]=grid[i1][j2]='*';
        } else {
            if (j1>0) {
                grid[i1][j1-1]=grid[i2][j2-1]='*';
            } else {
                grid[i1][j1+1]=grid[i2][j2+1]='*';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
