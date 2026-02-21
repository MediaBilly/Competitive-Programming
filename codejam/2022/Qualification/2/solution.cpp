#include <bits/stdc++.h>

using namespace std;

const int REQ_INK = 1e6;

int c[3], m[3], y[3], k[3];

void solve() {
    int minc = INT_MAX, minm = INT_MAX, miny = INT_MAX, mink = INT_MAX;
    for (int i = 0; i < 3; i++) {
        cin >> c[i] >> m[i] >> y[i] >> k[i];
        minc = min(minc, c[i]);
        minm = min(minm, m[i]);
        miny = min(miny, y[i]);
        mink = min(mink, k[i]);
    }
    int sum = minc + minm + miny + mink;
    while (sum > REQ_INK && minc > 0) {
        minc--;
        sum--;
    }
    while (sum > REQ_INK && minm > 0) {
        minm--;
        sum--;
    }
    while (sum > REQ_INK && miny > 0) {
        miny--;
        sum--;
    }
    while (sum > REQ_INK && mink > 0) {
        mink--;
        sum--;
    }
    if (sum == REQ_INK) {
        cout << minc << ' ' << minm << ' ' << miny << ' ' << mink << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
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
