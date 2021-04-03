#include <bits/stdc++.h>

using namespace std;

int n;
int a[300000],b[300000];
int zeros[300000],ones[300000];

void solve() {
    char c;
    cin >> n;
    memset(zeros,0,sizeof(zeros));
    memset(ones,0,sizeof(ones));
    for (int i = 0; i < n; i++) {
        cin >> c;
        a[i]=c-'0';
        if (i>0) {
            zeros[i] = zeros[i-1];
            ones[i]=ones[i-1];
        }
        if (a[i]==0) {
            zeros[i]++;
        } else {
            ones[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        b[i]=c-'0';
    }
    int i=n-1;
    bool flipped = false;
    while (i >= 0) {
        while (i >= 0 && (a[i]==b[i] && !flipped || a[i]!=b[i] && flipped)) {
            i--;
        }
        if (i >= 0) {
            if (zeros[i]!=ones[i]) {
                cout << "NO" << endl;
                return;
            }
            flipped = !flipped;
            i--;
        }
    }
    cout << "YES" << endl;
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
