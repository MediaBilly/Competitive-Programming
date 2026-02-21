#include <bits/stdc++.h>

using namespace std;

void solve() {
    int R,C;
    cin >> R >> C;
    cout << endl;
    for (int i = 0; i < 2 * R; i++) {
        for (int j = 0;j < C; j++) {
            if (i <= 1 && j == 0) {
                cout << "..";
            } else {
                cout << (i % 2 == 0 ? "+-" : "|.");
            }
        }
        cout << (i % 2 == 0 ? "+" : "|");
        cout << endl;
    }
    for (int i = 0; i < C; i++) {
        cout << "+-";
    }
    cout << "+" << endl;
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
