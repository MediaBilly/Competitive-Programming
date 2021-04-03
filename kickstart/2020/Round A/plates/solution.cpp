#include <bits/stdc++.h>

using namespace std;

int sum[51][31];
int dp[51][1500];

void solve(int x) {
    int N,K,P,beauty;
    cin >> N >> K >> P;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> beauty;
            sum[i][j] = sum[i][j-1] + beauty;
        }
    }
    for (int i = 1;i <= N;i++) {
        for (int j = 0;j <= P;j++) {
            dp[i][j] = 0;
            for (int x = 0;x <= min(j,K);x++) {
                dp[i][j] = max(dp[i][j],sum[i][x] + dp[i-1][j-x]);
            }
        }
    }
    cout << "Case #" << x << ": " << dp[N][P] << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
