#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int N;
    cin >> N;
    int X=0,O=0;
    int i=1;
    bool botTurn = true;
    while (i <= N) {
        if (botTurn) {
            X++;
            i+=2;
        } else {
            O++;
            i+=3;
        }
        botTurn = !botTurn;
    }
    cout << "Case #" << x << ": " << X << endl;
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
