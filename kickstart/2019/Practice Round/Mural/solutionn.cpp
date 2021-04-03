#include <bits/stdc++.h>

using namespace std;

int sec[5000000];

void solve(int x) {
    int N;
    cin >> N;
    int ans = 0,tmp,window = ceil((double)N/2);
    char c;
    for (int i = 0;i < N;i++) {
        cin >> c;
        sec[i] = c - '0';
        if (i < window) {
            ans += sec[i];
            tmp = ans;
        } else {
            tmp = tmp - sec[i - window] + sec[i];
            ans = max(ans,tmp);
        }
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
