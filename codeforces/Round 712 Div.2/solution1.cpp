#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s,suba,subb;
    cin >> s;
    // cout << s.length() <<endl;
    for (int i = 0; i < s.length(); i++) {
        if (s[s.length()-1-i] != 'a') {
            s.insert(s.begin()+i,'a');
            cout << "YES" << endl << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
