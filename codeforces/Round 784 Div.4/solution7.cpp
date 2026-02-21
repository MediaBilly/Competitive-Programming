#include <bits/stdc++.h>

using namespace std;

char grid[50][50];

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }

    for (int col = 0;col < m;col++) {
        cout << col << endl;
        int fl = n-1, s;
        while (fl > 0) {
            while (fl > 0 && grid[fl][col] == '*') {
                fl--;
            }
            if (grid[fl][col] == 'o') {
                fl--;
            }
            s = fl-1;
            while (s >= 0 && grid[s][col] == '.') {
                s--;
            }
            if (s >= 0 && fl > 0) {
                cout << fl << ' ' << s << endl;
                if (grid[s][col] == '*') {
                    grid[fl][col] = '*';
                    grid[s][col] = '.';
                } 
            }
            // fl = s-1;
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
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
