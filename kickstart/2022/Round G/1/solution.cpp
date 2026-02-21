#include <bits/stdc++.h>

using namespace std;

int S[1000][31];

void solve(int x) {
    int M,N,P;
    cin >> M >> N >> P;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    P--;
    int ans = 0;
    for (int i=0;i<N;i++) {
        int d = 0;
        for (int j = 0; j < M; j++) {
            if (j != P && S[j][i] > S[P][i]) {
                d = max(d,  S[j][i] - S[P][i]);
            }
        }
        ans+=d;
    }
    cout << "Case #" << x << ": " << ans << endl;
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
