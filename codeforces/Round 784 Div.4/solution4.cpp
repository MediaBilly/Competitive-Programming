#include <bits/stdc++.h>

using namespace std;

char row[100001];

void solve() {
    int n;
    cin >> n;
    unordered_set<char> state;
    for(int i = 0;i < n;i++) {
        cin >> row[i];
    }
    for (int i=0;i < n;i++) {
        if (row[i] == 'W') {
            if (state.size() == 1) {
                cout << "NO" << endl;
                return;
            } else {
                state.clear();
            }
        } else {
            state.insert(row[i]);
        } 
    }
    cout << (state.size() == 1 ? "NO" : "YES") << endl;
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
