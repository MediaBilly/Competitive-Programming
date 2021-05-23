#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    if (N <= 30) {
        for (int i = 1; i <= N; i++) {
            cout << i << " " << 1 << endl;
        }
        return;
    }
    N-=30;
    int rem=0;
    bool left = true;
    for (int row = 0; row < 30; row++) {
        cout << row+1 << " " << (left ? 1 : row+1) << endl;
        if (N & 0x1) {
            if (left) {
                for (int i = 1; i <= row; i++) {
                    cout << row+1 << " " << i+1 << endl;
                }
            } else {
                for (int i = row-1; i >= 0; i--) {
                    cout << row+1 << " " << i+1 << endl;
                }
            }
            left = !left;
            rem++;
        }
        N>>=1;
    }
    for (int row = 30;rem; rem--) {
        cout << row+1 << " " << (left ? 1 : row+1) << endl;
        row++;
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": " << endl;;
        solve();
    }
    return 0;
}
