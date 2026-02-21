#include <bits/stdc++.h>

using namespace std;

const int mod = 'z'-'a'+1;

int minop(char s, char f) {
    int a = (s-f)%mod, b = (f-s)%mod;
    if (a < 0) {
        a+=mod;
    }
    if (b < 0) {
        b+=mod;
    }
    cout << a << ' ' << b << '\n';
    return min(a, b);
}

void solve(int x) {
    string S,F;
    cin >> S >> F;
    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
        int m = INT_MAX;
        for (int j = 0; j < F.length(); j++) {
            char s = S[i]-'a', f = F[j]-'a';
            // cout << (int)s << ' ' << (int)f << ' ' << (s-f+mod)%mod  << ' ' << (f-s+mod)%mod << '\n';
            m = min(m, min((s-f+mod)%mod, (f-s+mod)%mod));
        }
        ans+=m;
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
