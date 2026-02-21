#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> idx;

void solve() {
    string s;
    cin >> s;
    cout << idx[s] << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int cnt = 1;
    for (char a = 'a';a <= 'z';a++) {
        for (char b = 'a';b <= 'z';b++) {
            if (a != b) {
                string s = "";
                s += a;
                s += b;
                idx[s] = cnt++;
            }
        }
    }
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
