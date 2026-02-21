#include <bits/stdc++.h>

using namespace std;

void solve() {
    int rating;
    cin >> rating;
    cout << "Division ";
    if (1900 <= rating) {
        cout << 1;
    } else if (1600 <= rating && rating <= 1899) {
        cout << 2;
    } else if (1400 <= rating && rating <= 1599) {
        cout << 3;
    } else {
        cout << 4;
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
