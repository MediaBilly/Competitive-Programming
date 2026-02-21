#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    string I, P;
    cin >> I >> P;
    int extra = 0;
    int i=0,j=0;
    while (i < I.length() && j < P.length()) {
        if (I[i] == P[j]) {
            i++;
            j++;
        } else {
            j++;
            extra++;
        }
    }
    extra += P.length() - j;
    cout << "Case #" << x << ": ";
    if (i == I.length()) {
        cout << extra;
    } else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;
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
