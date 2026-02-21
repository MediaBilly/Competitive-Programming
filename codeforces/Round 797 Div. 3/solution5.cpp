#include <bits/stdc++.h>
 
using namespace std;

int w[200000];
 
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> w[i];
    }
    sort(w, w+n, std::greater<int>());
    int ans = 0;
    for (int i=0;i<n;i+=2) {
        ans += (w[i] + w[i+1])/k;
    }
    cout << ans << endl;;
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