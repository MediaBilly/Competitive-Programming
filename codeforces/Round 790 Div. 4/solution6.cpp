#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    int num, minnum=INT_MAX, maxnum=INT_MIN;
    unordered_map<int, int> cnt;
    for (int i=0;i<n;i++) {
        cin >> num;
        minnum=min(minnum, num);
        maxnum=max(maxnum, num);
        if (cnt.find(num) == cnt.end()) {
            cnt[num]=0;
        }
        cnt[num]++;
    }
    bool impossible = true;
    for (int i = minnum;i<=maxnum;i++) {
        if (cnt.find(i) == cnt.end()) {
            cnt[i]=0;
        }
        if (cnt[i] >= k) {
            impossible = false;
        }
    }
    if (impossible) {
        cout << -1 << endl;
        return;
    }
    int l=minnum, r=l, maxdiff = -1, finalL=l, finalR=r;
    while (l <= maxnum && r <= maxnum) {
        while (r <= maxnum && cnt[r] >= k) {
            r++;
        }
        if (l <= maxnum && r <= maxnum) {
            if (r-l+1 > maxdiff) {
                maxdiff = r-l+1;
                finalL = l;
                finalR = r;
            }
        }
        while (r <= maxnum && cnt[r]==0) {
            r++;
        }
        l = r;
    }
    cout << finalL << ' ' << finalR << endl << endl;
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
