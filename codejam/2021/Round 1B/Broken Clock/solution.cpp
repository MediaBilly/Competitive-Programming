#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;

const ll ns = 1e9;

// Full circle
const uint64_t M = 360 * 12 * 1e10;

void solve() {
    vector<ll> hand(3);
    cin >> hand[0] >> hand[1] >> hand[2];
    do {
        ll diff = hand[1] - hand[0];
        for (int h=0;h<=11;h++) {
            if ((3600*ns*h + diff) % 11 == 0) {
                ll X = (3600*ns*h + diff)/11;
                unsigned long long t = 3600*ns*h + X;
                ll R = hand[0] - 3600*ns*h - X;
                if (hand[2] == (R + 720 * t) % M && hand[1] == (R + 12 * t) % M && hand[0] == (R + t) % M) {
                    ll hrs = t / (3600*ns);
                    t = t % (3600*ns);
                    ll m = t/(60*ns);
                    t = t % (60*ns);
                    ll s = t/ns;
                    ll n = t % ns;
                    cout << hrs << ' ' << m << ' ' << s << ' ' << n << endl;
                    return;
                }
            }
        }
    } while (next_permutation(hand.begin(),hand.end()));
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
