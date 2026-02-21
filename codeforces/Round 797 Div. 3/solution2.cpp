#include <bits/stdc++.h>
 
using namespace std;
 
int a[50000], b[50000];
 
void solve() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
 
    bool fdiff = false;
    int diff = -1;
    for (int i=0;i<n;i++) {
        if (b[i]!=0) {
            if (b[i] > a[i]) {
                cout << "NO" << endl;
                return;
            }
            if (!fdiff) {
                fdiff = true;
                diff = a[i] - b[i];
            } else if (a[i] - b[i] != diff) {
                cout << "NO" << endl;
                return;
            }
        } 
    }
    if (fdiff)
    for (int i=0;i<n;i++) {
        if (b[i]==0 && a[i]>diff) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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