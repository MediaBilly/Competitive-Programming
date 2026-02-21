#include <bits/stdc++.h>

using namespace std;

int PSUM[400000];
int A[400000];

int F(int L, int R) {
    return PSUM[R] - (L > 0 ? PSUM[L-1] : 0);
}

bool isHappy(int L, int R) {
    for (int r = L;r <= R;r++) {
        if (F(L,r) < 0) {
            return false;
        }
    }
    return true;
}

void solve(int x) {
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }
    PSUM[0] = A[0];
    for (int i=1;i<N;i++) {
        PSUM[i] = PSUM[i-1] + A[i];
    }
    long long ans = 0;
    for (int l=0;l<N;l++) {
        for (int r=l;r<N;r++) {
            if (isHappy(l,r)) {
                ans += F(l, r);
            }
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
