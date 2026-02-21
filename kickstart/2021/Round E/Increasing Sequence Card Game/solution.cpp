#include <bits/stdc++.h>

using namespace std;

double h[(int)1e6];

void solve(int x) {
    unsigned long long N;
    cin >> N;
    double ans;
    if (N <= (int)1e6) {
        ans = h[N];
    } else {
        ans = h[(int)1e6] + log(N+1) - log(1e6+1);
    }
    cout << "Case #" << x << ": " << fixed << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    h[0] = 0;
    for (int i = 1; i <= 1e6; i++) {
        h[i] = h[i-1] + 1.0/i;
    }
    cout.precision(6);
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
