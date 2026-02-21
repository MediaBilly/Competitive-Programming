#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int h1=3,h2=2,h3=1;
    n-=6;
    while (n) {
        h1++;
        n--;
        if (n) {
            h2++;
            n--;
        }
         if (n) {
            h3++;
            n--;
        }
    }
    cout << h2 << ' ' << h1 << ' ' << h3 << endl;
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
