#include <bits/stdc++.h>

using namespace std;

int X[100];

int digits(int num) {
    int ret=0;
    while (num > 0) {
        ret++;
        num/=10;
    }
    return ret;
}

int firstdigit(int num) {
    while (num >= 10) {
        num/=10;
    }
    return num;
}

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    int ans=0;
    for (int i = 1; i < N; i++) {
        int num = X[i];
        int ds = digits(num),ds1=digits(X[i-1]);
        int newds=0;
        while (ds < ds1) {
            num*=10;
            ds++;
            newds++;
            ans++;
        }
        if (num <= X[i-1]) {
            if (firstdigit(X[i-1]) == firstdigit(num)) {
                if (num != X[i]) {
                    int lim = 1;
                    for (int i = 0; i < newds; i++) {
                        lim *= 10;
                    }
                    if (abs(num - X[i-1]) < lim-1) {
                        num+=abs(num - X[i-1])+1;
                    } else {
                        num *=10;
                        ans++;
                    }
                } else {
                    num *=10;
                    ans++;
                }
            } else if (firstdigit(X[i-1]) > firstdigit(num)) {
                num *= 10;
                ans++;
            }
        }
        X[i]=num;
    }
    
    cout << ans << endl;
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
