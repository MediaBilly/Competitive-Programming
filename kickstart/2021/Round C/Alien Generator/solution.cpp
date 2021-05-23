#include <bits/stdc++.h>

using namespace std;

bool check(unsigned long long K, unsigned long long G) {
    double i = (2.0 * G - K * K - K)/(2.0*(K+1));
    return i > 0 && i == floor(i);
}

void solve(int x) {
    unsigned long long G;
    cin >> G;
    unsigned long long ans = 0;
    unsigned long long h = sqrt(2 * G);
    for (unsigned long long K = 0;K <= h; K++) {
        if (check(K,G)) {
            ans++;
        }
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
