#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    for (int i=0;i<S.length();) {
        int next = i+1;
        while (next < S.length() && S[next] == S[i]) {
            next++;
        }
        while (i < next) {
            cout << S[i];
            if (next < S.length() && S[i] < S[next]) {
                cout << S[i];
            }
            i++;
        }
    }
    
    cout << endl;
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
