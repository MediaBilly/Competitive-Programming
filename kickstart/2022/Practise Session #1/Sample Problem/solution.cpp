#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int ans = 0;
    int N,M,Ci;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> Ci;
        ans+=Ci;
    }
    cout << "Case #" << x << ": " << ans % M << endl;
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
