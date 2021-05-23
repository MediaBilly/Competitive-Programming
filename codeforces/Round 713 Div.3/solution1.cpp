#include <bits/stdc++.h>

using namespace std;

int a[100],cnt[101],idx[101];

void solve() {
    int n;
    cin >> n;
    memset(cnt,0,sizeof(cnt));
    memset(idx,-1,sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (idx[a[i]]==-1) {
            idx[a[i]]=i;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i]==1) {
            cout << idx[i]+1 << endl;
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
