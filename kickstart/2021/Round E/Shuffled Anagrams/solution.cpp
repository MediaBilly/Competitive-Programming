#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    string S;
    cin >> S;
    string A = S;
    bool ok = false;
    for (int i = 0; i < S.size(); i++) {
        if (A[i] != S[i]) {
            continue;
        }
        int j = (i+1) % S.size();
        while (j != i) {
            if (A[j] != A[i] && A[i] != S[j]) {
                char tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                break;
            }
            j = (j+1) % S.size();
        }
        if (j == i) {
            cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
            return;
        }
    }
    
    cout << "Case #" << x << ": " << A << endl;
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
