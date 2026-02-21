#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int R,A,B;
    cin >> R >> A >> B;
    int radius = R;
    double ans = 0;
    while (radius > 0) {
        ans += M_PI * radius * radius;
        radius *= A;
        if (radius > 0) {
            ans += M_PI * radius * radius;
            radius /= B;
        }
    }
    cout << "Case #" << x << ": " << fixed << setprecision(6) << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    // setprecision(6);
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
