#include <bits/stdc++.h>

using namespace std;

bool ok(string t) {
    unordered_set<char> seen;
    char cur = ' ';
    for (int j = 0;j < t.length();j++) {
        if (t[j] != cur) {
            if (seen.find(t[j]) != seen.end()) {
                return false;
            } else {
                seen.insert(t[j]);
                cur = t[j];
            }
        } 
    }
    return true;
}

// Returns true if a is prefix of b
bool isPrefixOf(string a, string b) {
    if (b.length() < a.length()) {
        return false;
    }
    for (int i=0;i<a.length();i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

ssize_t numLetters(string s) {
    unordered_set<char> lets;
    for (int i = 0;i<s.length();i++) {
        lets.insert(s[i]);
    }
    return lets.size();
}

void solve() {
    // Read input
    int N;
    cin >> N;
    unordered_set<string> towers;
    for (int i=0;i<N;i++) {
        string S;
        cin >> S;
        if (ok(S)) {
            bool special = false;
            for (string s: towers) {
                if (S == s) {
                    towers.erase(s);
                    towers.insert(s + s);
                    special = true;
                    break;
                } else if ((numLetters(s) == 1) && (numLetters(S) == 1) && (isPrefixOf(S,s) || isPrefixOf(s, S))) {
                    towers.insert(s + S);
                    towers.erase(s);
                    special = true;
                    break;
                }
            }
            if (!special) {
                if (towers.find(S) != towers.end()) {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                } else {
                    towers.insert(S);
                }
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
