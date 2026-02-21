#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x,y;
    cin >> x >> y;
    if (y < x || y % x != 0) {
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    int z = y / x;
    if (z == 1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    for (int b = 2;b <= z;b++) {
        int tmp = 1, a = 0;
        while (tmp < z) {
            // cout << a << ' ' << b << endl;
            a++;
            tmp *= b;
        }
        if (tmp == z) {
            cout << a << ' ' << b << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
