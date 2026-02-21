#include <bits/stdc++.h>

using namespace std;

int a[50];

void solve() {
    int n;
    cin >> n;
    int ma=INT_MAX;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        ma = min(ma, a[i]);
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        ans += a[i] - ma;
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
