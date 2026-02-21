#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, x ,y;
    cin >> a >> b >> c >> x >> y;
    if (x >= a)
        x -= a;
    else {
        a -= x;
        x = 0;
    }
    
    if (y >= b)
        y -= b;
    else {
        b -= y;
        y = 0;
    }
    if (c >= x + y) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
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
