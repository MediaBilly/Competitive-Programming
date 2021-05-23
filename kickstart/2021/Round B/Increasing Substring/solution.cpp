#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << "Case #" << x << ": ";
    for (int i = 0,j=0; i < N; i++) {
        if (i > 0 && S[i]<=S[i-1]) {
            j = i;
        }
        cout << i - j + 1 << " ";
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
