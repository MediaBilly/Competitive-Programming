#include <bits/stdc++.h>

using namespace std;

int a[30];

bool ok(int n) {
    for (int i=1;i<n;i++) {
        if (a[i] <= a[i-1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        // cout << a[i] << ' ';
    }
    // cout << endl;
    int ops = 0;
    bool run = true;
    while (run) {
        run = false;
        for (int i = 0;i < n-1;i++) {
            if (a[i+1] <= a[i]) {
                if (a[i] == 0) {
                    cout << -1 << endl;
                    return;
                }
                run = true;
                ops++;
                a[i]/=2;
            }
            // cout << a[i] << ' ';
        }
        // cout << a[n-1] << endl;;
    }
    if (!ok) {
        ops = -1;
    }
    cout << ops << endl;
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
