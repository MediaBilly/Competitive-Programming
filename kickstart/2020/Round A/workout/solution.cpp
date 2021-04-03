#include <bits/stdc++.h>

using namespace std;

int d[100000];

void solve(int x) {
    int N,K,M1,M2,maxD,dOpt,KSUM;
    cin >> N >> K;
    cin >> M1;
    maxD = -1;
    for (int i = 0;i < N-1;i++) {
        cin >> M2;
        d[i] = M2 - M1;
        maxD = max(maxD,d[i]);
        M1 = M2;
    }
    int l=1,r=maxD,mid;
    while (l < r) {
        mid = l + (r - l)/2;
        KSUM = 0;
        for (int i = 0;i < N - 1;i++) {
            KSUM += ceil((double)d[i]/mid) - 1;
        }
        if (KSUM <= K) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << "Case #" << x << ": " << l << endl;
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
