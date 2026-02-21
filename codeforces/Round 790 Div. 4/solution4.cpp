#include <bits/stdc++.h>

using namespace std;

long long rdiagSum[200][200], ldiagSum[200][200];

int a[200][200];

void calcDiagSum(int n, int m, int ioffset, int joffset, bool right = true) {
    int ans = 0;
    for (int i=0+ioffset, j=0+joffset;i < n && j < m && j >= 0;) {
        ans += a[i][j];
        // cout << i << ' ' << j << ' ' << right << endl;
        i++;
        if (right) 
            j++;
        else 
            j--;
    }
    for (int i=0+ioffset, j=0+joffset;i < n && j < m && j >= 0;) {
        if (right)
            rdiagSum[i][j] = ans;
        else 
            ldiagSum[i][j] = ans;
        i++;
        if (right) 
            j++;
        else 
            j--;
    }
    // cout << ans << endl << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i =0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n-1;i >= 0;i--) {
        calcDiagSum(n, m, i, 0);
        calcDiagSum(n, m, i, m-1, false);
    }
    for (int j = m-1;j >= 0;j--) {
        calcDiagSum(n, m, 0, j);
        calcDiagSum(n, m, 0, j, false);
    }

    long long ans = LONG_MIN;
    for (int i =0;i<n;i++) {
        for (int j =0;j<m;j++) {
            // cout << i << ' ' << j << ' ' << ldiagSum[i][j] + rdiagSum[i][j] << endl;
            ans = max(ans, ldiagSum[i][j] + rdiagSum[i][j] - a[i][j]);
        }
    }
    cout << ans << endl;
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
