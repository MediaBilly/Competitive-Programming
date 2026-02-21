#include <bits/stdc++.h>

using namespace std;

int a[200000];

void solve() {
    int n;
    cin >> n;
    int mina = INT_MAX, minpos = 0;
    int maxa = INT_MIN, maxpos = 0;
    unordered_set<int> nums;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        nums.insert(a[i]);
        if (a[i] < mina) {
            mina = a[i];
            minpos = i;
        }
        if (a[i] > maxa) {
            maxa = a[i];
            maxpos = i;
        }
    }
    if (nums.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    if (n <= 2) {
        cout << "YES" << endl;
        return;
    }
    if (n == 3) {
        if (minpos == 0 && (maxpos == n-2 || maxpos == n-1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    if ((minpos == 0 || minpos == 1) && (maxpos == n-2 || maxpos == n-1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
