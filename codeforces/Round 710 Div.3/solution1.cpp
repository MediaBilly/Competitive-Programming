#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve() {
    ull n,m,x;
    cin >> n >> m >> x;
    ull i = (x-1) / n;
    ull j = (x-1) % n;
    cout << m * j + i + 1 << endl;
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
