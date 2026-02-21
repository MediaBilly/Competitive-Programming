#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int k = 0;
    for (int i = 0; i < N-1; i++) {
        char a, b, tmp;
        while(i>=0 && S[i] + 1 == S[i+1] || S[i] == '9' && S[i+1]=='0') {
            a = S[i], b = S[i+1];
            tmp = b+1;
            if (tmp > '9') {
                tmp = '0';
            }
            S.replace(i, 2, string(1, tmp));
            i--;
            N--;
            // cout << i << ' ' << S << endl;
        }
        if (i < 0) i++;
    }
    cout << "Case #" << x << ": " << S << endl;
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
