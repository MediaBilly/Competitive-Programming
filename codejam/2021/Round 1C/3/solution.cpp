#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S,E;
    cin >> S >> E;
    bitset<100> BS1(S);
    bitset<100> BS2(E);
    cout << (BS1 << 2) << endl;
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
