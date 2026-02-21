#include <bits/stdc++.h>

using namespace std;

unordered_set<string> strs;

bool hasa(string s) {
    for (char c: s) {
        if (c == 'a') {
            return true;
        }
    }
    return false;
}

void solve() {
    string s,t;
    cin >> s >> t;
    strs.clear();
    if (hasa(t)) {
        if (t.length() > 1) {
            cout << -1 << endl;
        } else if (t.length() == 1) {
            cout << 1 << endl;
        }
        return;
    }
    cout << ((unsigned long long)1 << s.length()) << endl;
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
