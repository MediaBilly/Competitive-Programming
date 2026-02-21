#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n,q;
    cin >> n >> q;
    int sum = 0;
    vector<int> a;
    int ai;
    for (int i=0;i<n;i++) {
        cin >> ai;
        sum += ai;
        a.push_back(ai);
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<int> psum;
    psum.push_back(a[0]);
    for (int i=1;i<n;i++) {
        psum.push_back(psum[i-1] + a[i]);
    }
    int x;
    for (int i=0;i<q;i++) {
        cin >> x;
        if (x > sum) {
            cout << -1 << endl;
            continue;
        }
        if (psum[0] >= x) {
            cout << 1 << endl;
            continue;
        }
        int l = 1, r = n-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (psum[mid] >= x && psum[mid-1] < x) {
                cout << mid + 1 << endl;
                break;
            } else if (psum[mid-1] >= x) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
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
