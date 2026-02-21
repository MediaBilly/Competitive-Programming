#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    long long N,D,C,M;
    cin >> N >> D >> C >> M;
    string S;
    cin >> S;
    long long dogs = 0;
    for (int i=0;i< N;i++) {
        if (S[i] == 'D')
            dogs++;
    }
    for (int i=0;i<N;i++) {
        if (S[i] == 'D') {
            if (D > 0) {
                dogs--;
                D--;
                C += M;
            } else {
                break;
            }
        } else if (S[i] == 'C') {
            if (C > 0) {
                C--;
            } else {
                break;
            }
        }
    }
    cout << "Case #" << x << ": " << (dogs == 0 ? "YES" : "NO") << endl;
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
