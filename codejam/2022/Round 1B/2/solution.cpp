#include <bits/stdc++.h>

using namespace std;

int N,P;

int minp[1001], maxp[1001];

long long dp[1001][2];

void solve() {
    cin >> N >> P;
    for (int i=0;i<N;i++) {
        int mi = INT_MAX, ma = INT_MIN, tmp;
        for (int j=0;j<P;j++) {
            cin >> tmp;
            mi = min(mi, tmp);
            ma = max(ma, tmp);
        }
        minp[i+1] = mi;
        maxp[i+1] = ma;
    }
    dp[0][0] = dp[0][1] = 0;
    long long l0 = 0, l1 = 0;
    for (int i=1;i<=N;i++) {
        dp[i][0] = min(dp[i-1][0] + abs(minp[i] - l0) + maxp[i] - minp[i], dp[i-1][1] + abs(minp[i] - l1) + maxp[i] - minp[i]);
        dp[i][1] = min(dp[i-1][0] + abs(maxp[i] - l0) + maxp[i] - minp[i], dp[i-1][1] + abs(maxp[i] - l1) + maxp[i] - minp[i]);
        l0 = maxp[i];
        l1 = minp[i];
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
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
