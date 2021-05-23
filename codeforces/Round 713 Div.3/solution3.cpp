#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    int l=0,r=s.length()-1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='0') {
            a--;
        } else if (s[i]=='1') {
            b--;
        }
    }
    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }
    while (l <= r) {
        if (s[l]=='?' || s[r]=='?') {
            if (s[l]!=s[r]) {
                if (s[l]=='?') {
                    if (s[r]=='0') {
                        if (a > 0) {
                            s[l]='0';
                            a--;
                        } else {
                            cout << -1 << endl;
                            return;
                        }
                    } else if (s[r]=='1') {
                        if (b > 0) {
                            s[l]='1';
                            b--;
                        } else {
                            cout << -1 << endl;
                            return;
                        }
                    }
                } else if (s[r]=='?') {
                    if (s[l]=='0') {
                        if (a > 0) {
                            s[r]='0';
                            a--;
                        } else {
                            cout << -1 << endl;
                            return;
                        }
                    } else if (s[l]=='1') {
                        if (b > 0) {
                            s[r]='1';
                            b--;
                        } else {
                            cout << -1 << endl;
                            return;
                        }
                    }
                }
            } else {
                if (l < r) {
                    if (a >= 2) {
                        s[l]=s[r]='0';
                        a-=2;
                    } else if (b >= 2) {
                        s[l]=s[r]='1';
                        b-=2;
                    } else {
                        cout << -1 << endl;
                        return;
                    }
                } else {
                    if (a == 1 && b == 0) {
                        s[l]='0';
                        a--;
                    } else if (b == 1 && a == 0) {
                        s[l]='1';
                        b--;
                    }
                }
            }
        } else {
            if (s[l]!=s[r]) {
                cout << -1 << endl;
                return;
            } 
            // else {
            //     if (s[l]=='0') {
            //         a--;
            //     } else {
            //         b--;
            //     }
            //     if (a < 0 || b < 0) {
            //         cout << -1 << endl;
            //         return;
            //     }
            // }
        }
        l++;
        r--;
    }
    cout << s << endl;
    // if (a+b==0) {
    //     cout << s << endl;
    // } else {
    //     cout << -1 << endl;
    // }
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
