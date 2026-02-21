#include <bits/stdc++.h>
 
using namespace std;
 
int s[200000], f[200000];
 
void solve() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    for (int i=0;i<n;i++) {
        cin >> f[i];
    }

    cout << f[0] - s[0] << ' ';
    for (int i=1;i<n;i++) {
        if (f[i-1] <= s[i]) {
            cout << f[i] - s[i];
        } else {
            cout << f[i] - f[i-1];
        }
        cout << ' ';
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