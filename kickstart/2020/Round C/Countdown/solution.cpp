#include <bits/stdc++.h>

using namespace std;

int A[200000];

void solve(int x) {
    int ans = 0;
    int N,K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cd = 0;
    for (int i = N-1; i >= 0; i--) {
        if (cd == K) {
            ans++;
            cd = 0;
        }
        if (A[i] == cd + 1) {
            cd++;
        } else {
            cd = A[i] == 1;
        }
    }
    if (cd == K) {
        ans++;
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
