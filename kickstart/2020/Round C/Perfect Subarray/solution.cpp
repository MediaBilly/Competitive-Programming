#include <bits/stdc++.h>

using namespace std;

int A[100000];
int P[20000001];

void solve(int x) {
    long long ans = 0;
    int N;
    cin >> N;
    int maxpSum = 0;
    int offset = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            offset -= A[i];
        } else {
            maxpSum += A[i];
        }
    }
    int prefix_sum = 0;
    memset(P,0,sizeof(P));
    P[offset]++;
    for (int i = 0; i < N; i++) {
        prefix_sum += A[i];
        for (int k = 0;k * k <= maxpSum;k++) {
            if ((prefix_sum - k * k) + offset >= 0) {
                ans += P[(prefix_sum - k * k) + offset];
            }
        }
        P[prefix_sum + offset]++;
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
