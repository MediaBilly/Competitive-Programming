#include <bits/stdc++.h>

using namespace std;

string a,b;

void solve() {
    cin >> a >> b;
    int ans = a.length()+b.length();
    string suba,subb;
    for (int sa = 0; sa < a.length(); sa++) {
        for (int ea = a.length()-1; ea >= sa; ea--) {
            for (int sb = 0; sb < b.length(); sb++) {
                for (int eb = b.length()-1; eb >= sb; eb--) {
                    suba = a.substr(sa,ea-sa+1);
                    subb = b.substr(sb,eb-sb+1);
                    int tmp = a.length()-suba.length()+b.length()-subb.length();
                    if (suba == subb) {
                        ans = min(ans,tmp);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
