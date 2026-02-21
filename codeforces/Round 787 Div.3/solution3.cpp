#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    // 1st case: length 1
    if (s.length() == 1) {
        cout << 1 << endl;
        return;
    }
    // 2nd case: only ? => everyone is suspect
    bool everyone = true;
    for (char c: s) {
        if (c != '?') {
            everyone = false;
            break;
        }
    }
    if (everyone) {
        cout << s.length() << endl;
        return;
    }
    // general case
    int last1 = 0;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '0') {
            cout << i - last1 + 1 << endl;
            return;
        } else if (s[i] == '1') {
            last1 = i;
        }
    }
    cout << s.length() - last1 << endl;
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
