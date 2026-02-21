#include <bits/stdc++.h>

using namespace std;

int n;
int a[50];

bool sameParity(bool evenIndex) {
    bool evenPar = a[evenIndex ? 0 : 1] % 2 == 0;
    for (int i =(evenIndex ? 0 : 1);i < n;i+=2) {
        if (evenPar) {
            if (a[i] % 2 == 1) {
                return false;
            }
        } else {
            if (a[i] % 2 == 0) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << (sameParity(false) && sameParity(true) ? "YES" : "NO") << endl;
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
