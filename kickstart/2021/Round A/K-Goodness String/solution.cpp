#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int N,K,goodness=0;
    cin >> N >> K;
    string str;
    cin >> str;
    for (int i = 0; i < N/2; i++) {
        if (str[i]!=str[N-1-i]) {
            goodness++;
        }
    }
    // cout << goodness << endl;
    // int ans = 0;
    // for (int i = 0; i < N/2 && goodness > K; i++) {
    //     if (str[i]!=str[N-1-i]) {
    //         ans++;
    //         goodness--;
    //     }
    // }
    // for (int i = 0; i < N/2 && goodness < K; i++) {
    //     if (str[i]==str[N-1-i]) {
    //         ans++;
    //         goodness++;
    //     }
    // }
    cout << "Case #" << x << ": " << abs(goodness - K) << endl;
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
