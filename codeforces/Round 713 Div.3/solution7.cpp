#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000000;

int Dinv[maxn+1];
long long sd[maxn+1];

void solve() {
    int c;
    cin >> c;
    cout << Dinv[c] << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    memset(Dinv,-1,sizeof(Dinv));
    memset(sd,0,sizeof(sd));
    for (int n = 1; n <= maxn; n++) {
        for (int muln = n; muln <= maxn; muln+=n) {
            sd[muln]+=n;
        }
        if (sd[n] <= maxn) {
            if (Dinv[sd[n]] == -1) {
                Dinv[sd[n]] = n;
            }
        }
    }
    
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
