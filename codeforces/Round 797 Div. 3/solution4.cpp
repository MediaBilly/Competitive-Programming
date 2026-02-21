#include <bits/stdc++.h>
 
using namespace std;

vector<int> s, e;

int len(int i) {
    return e[i] - s[i] + 1;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;

    s.clear();
    e.clear();

    bool b=false;
    int st=-1,en=st;
    for (int i=0;i<n;i++) {
        if (!b && S[i] =='B') {
            b= true;
            st=i;
        } else if (b && S[i] == 'W') {
            b = false;
            en = i-1;
            s.push_back(st);
            e.push_back(en);
        }
    }
    if (b) {
        en = n-1;
        s.push_back(st);
        e.push_back(en);
    }

    if (s.size() == 0) {
        cout << n << endl;
        return;
    }

    int maxs = -1, maxc = INT_MIN;
    for (int i=0;i<s.size();i++) {
        if (e[i] - s[i] > maxc) {
            max = e[i] - s[i] + 1;
            maxs = i;
        }
    }

    int last = i;
    int cur = len(last);
    while (cur < n) {
        bool left = false; right = false;
        if (last > 0) {
            if (len(last-1) + cur > n) {
                left = 
            }
        }
    }
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