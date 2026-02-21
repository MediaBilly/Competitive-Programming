#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int L,N;
    cin >> L >> N;
    int d = 0;
    char prevDir = ' ';
    unsigned long long ans = 0;
    for (int i = 0; i < N; i++) {
        int Di;
        char Ci;
        cin >> Di >> Ci;
        if (i == 0 || d == 0) {
            prevDir = Ci;
        }
        if (Ci == 'A') {
            Di *= -1;
        }
        int newLaps = 0;
        if (Ci == 'C' && d + Di >= L)
            newLaps += (d + Di) / L;
        else if (Ci == 'A' && d + Di <= 0) {
            newLaps += -(d + Di) / L + (d != 0);
        }
        bool changeDir = false;
        // Change direction
        if (Ci != prevDir && newLaps > 0) {
            newLaps--;
            changeDir = true;
        }
        ans += newLaps;
        d = ((d + Di) % L + L) % L;
        // cout << d << ' ' << ans << endl;
        if (changeDir)
            prevDir = Ci;
    }
    cout << "Case #" << x << ": " << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
