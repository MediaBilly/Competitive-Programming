#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

// HINT: Skip numbers that have at least one 0!!!

bool isInteresting(ULL num) {
    ULL p = 1;
    int sum = 0;
    ULL tmp = num;;
    while (tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
    }
    while (num > 0) {
        p *= (num % 10);
        if (p % sum == 0) {
            return true;
        }
        num /= 10;
    }
    return p % sum == 0;
}

void solve(int x) {
    ULL A,B;
    cin >> A >> B;
    int ans = 0;
    for (ULL i = A; i <= B; i++) {
        if (isInteresting(i)) {
            // cout << i << " is interesting\n";
            ans++;
        }
    }
    
    cout << "Case #" << x << ": " << ans << endl;
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
