#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int a,b;
    cin >> a >> b;
    int E=a * (b+1) + b * (a+1),V=(a+1) * (b+1);
    cout << E - V + 1 << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
