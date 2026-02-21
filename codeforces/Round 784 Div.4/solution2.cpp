#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (cnt.find(a) == cnt.end()) {
            cnt[a] = 1;
        } else {
            cnt[a]++;
        }
    }
    for (auto a: cnt) {
        if (a.second >= 3) {
            cout << a.first << endl;
            return;
        }
    }
    cout << -1 << endl;
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
