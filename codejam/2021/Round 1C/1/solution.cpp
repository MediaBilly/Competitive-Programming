#include <bits/stdc++.h>

using namespace std;

int P[30];
// Min dist of every possible k to all the P tickets
vector<int> minDist;

void solve() {
    int N,K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    minDist.reserve(K);
    for (int k = 1;k <= K; k++) {
        int md = INT_MAX;
        for (int i = 0; i < N; i++) {
            md = min(md,abs(k - P[i]));
            //cout << i << " " << minDist[k] << endl;
        }
        minDist[k] = md;
    }
    
    double maxProb = 0.0;
    for (int T1 = 1; T1 <= K; T1++) {
        for (int T2 = T1; T2 <= K; T2++) {
            double wins = 0.0;
            for (int c = 1; c <= K; c++) {
                cout << abs(T1 - c) - minDist[c] << " " << abs(T2 - c) - minDist[c] << endl;
                //cout << T1 << " " << T2 << " " << c << " " << abs(T1 - c) << " " << abs(T2 - c) << " " << minDist[T1] << " " << minDist[T2] << endl;
                if (abs(T1 - c) < minDist[c] || abs(T2 - c) < minDist[c]) {
                    wins++;
                }
            }
            cout << "---\n";
            //cout << T1 << " " << T2 << " " << wins << endl;
            //maxProb = max(maxProb,wins/((double)K));
            if (wins/((double)K) > maxProb) {
                maxProb = max(maxProb,wins/((double)K));
                //cout << T1 << " " << T2 << " " << maxProb << endl;
            }
        }
    }
    
    cout << maxProb << endl;
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
