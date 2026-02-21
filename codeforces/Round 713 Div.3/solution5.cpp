#include <bits/stdc++.h>

using namespace std;

int low(int k) {
    return k * (k+1)/2;
}

int high(int n, int k) {
    return k * (2 * n + 1 - k)/2;
}

void solve() {
    int n,l,r,s;
    cin >> n >> l >> r >> s;
    vector<int> ans(n);
    int segptr = l-1;
    unordered_set<int> seg;
    for (int i = n,k = r - l + 1;k > 0 && i >= 1; i--) {
        if (high(i,k) >= s && s - i >= low(k - 1)) {
            ans[segptr++] = i;
            seg.insert(i);
            s-=i;
            k--;
        }
    }
    if (s > 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1,ptr=0; i <= n;i++) {
        if (ptr == l-1) {
            ptr = r;
        }
        if (seg.find(i) == seg.end()) {
            ans[ptr++] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
