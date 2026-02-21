#include <bits/stdc++.h>

using namespace std;

int S[100000];

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S, S+N);
    int curNum = 1;
    for (int i = 0; i < N; i++) {
        if (curNum <= S[i]) {
            curNum++;
        }
    }
    cout << curNum - 1 << endl;
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
