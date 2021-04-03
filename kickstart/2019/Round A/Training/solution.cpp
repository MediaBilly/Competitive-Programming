#include <bits/stdc++.h>

using namespace std;

int S[100000];

void solve(int x) {
    int N,P,ans,tTime=0;
    cin >> N >> P;
    for (int i = 0;i<N;i++) {
        cin >> S[i];
    }
    sort(S,S+N);
    for (int i = 0;i < P;i++) {
        tTime+=S[i];
    }
    ans = P * S[P-1] - tTime;
    for (int i = 1;i <= N - P;i++) {
        tTime = tTime - S[i-1] + S[i + P - 1];
        ans = min(ans,P * S[i + P - 1] - tTime);
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
