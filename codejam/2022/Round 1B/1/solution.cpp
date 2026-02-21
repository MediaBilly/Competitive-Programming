#include <bits/stdc++.h>

using namespace std;

int d[100000];

void solve() {
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> d[i];
    }
    int ans = 0;
    int l = 0, r = N-1, maxpaid = 0;
    while (l <= r) {
        int cur;
        if (d[l] < d[r]) {
            cur = d[l++];
        } else {
            cur = d[r--];
        }
        if (cur >= maxpaid) {
            ans++;
        }
        maxpaid = max(maxpaid, cur);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
