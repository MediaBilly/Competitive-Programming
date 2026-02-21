#include <bits/stdc++.h>

using namespace std;

int w[200000];

void solve() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> w[i];
    }
    int p1 = -1, p2 = n;
    int ans = 0, s1=0, s2 = 0;
    while (p1 < p2) {
        if (s1 <= s2) {
            s1 += w[++p1];
        } else {
            s2 += w[--p2];
        }
        if (s1 == s2 && p1 < p2) {
            ans = max(ans, p1+1 + n-p2);
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
