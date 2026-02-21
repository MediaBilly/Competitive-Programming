#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve() {
    int N,K;
    cin >> N >> K;
    ll sum = 0;
    ll sumOfSq = 0;
    for (int i = 0;i < N;i++) {
        int E;
        cin >> E;
        sum += E;
        sumOfSq += E * E;
    }
    if (sum == 0) {
        if (sumOfSq == 0) {
            cout << 0 << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        return;
    }

    if ((sumOfSq - sum * sum) % (2 * sum) == 0) {
        cout << (sumOfSq - sum * sum) / (2 * sum) << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
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
