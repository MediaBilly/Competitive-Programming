#include <bits/stdc++.h>

using namespace std;

const long double tickDegrees = 1/(12 * 10e9);
int degsPerHour = 30;
int degsPerMin = 6;
int degsPerSecond = 6;

void solve() {
    unsigned long long A,B,C;
    cin >> A >> B >> C;
    int h=0,m=0,s=0,n=0;
    A *= tickDegrees;
    B *= tickDegrees;
    C *= tickDegrees;
    // s += C / degsPerSecond;
    // n = C % degsPerSecond;
    // m += s / 60;
    // s %= 60;
    // h += m / 60;
    // m %= 60;
    // m += B / degsPerMin;
    
    // cout << A << " " << B  << " " << C  << endl;
    
    if (A/degsPerSecond == 0 || A/degsPerSecond > B / degsPerMin)
        cout << C / degsPerHour << " " << B / degsPerMin << " " << A / degsPerSecond << " " << n << endl;
    else 
        cout << C / degsPerHour << " " << A / degsPerSecond << " " << B / degsPerMin << " " << n << endl;
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
