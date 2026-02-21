#include <bits/stdc++.h>

using namespace std;

void solve() {
    string ticket; cin >> ticket;
    int s1 = 0, s2 = 0;
    for (int i = 0;i < 3;i++) {
        s1 += ticket[i] - '0';
        s2 += ticket[5-i] - '0';
    }
    cout << (s1 == s2 ? "YES" : "NO") << endl;
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
