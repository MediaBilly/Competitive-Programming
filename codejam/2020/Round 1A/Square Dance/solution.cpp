#include <bits/stdc++.h>

using namespace std;
int S[10001][10001];

void solve() {
    int R,C;
    cin >> R >> C;
    long long ans=0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> S[i][j];
        } 
    }
    bool loop=true;
    do {
        vector<pair<int,int>> rem;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ans+=S[i][j];
                if(S[i][j]!=0) {
                    int n=0;
                    double tmp=0.0;
                    for (int k = i+1;k < R; k++) {
                        if (S[k][j]!=0) {
                            tmp+=S[k][j];
                            n++;
                            break;
                        }
                    }
                    for (int k = i-1;k >= 0; k--) {
                        if (S[k][j]!=0) {
                            tmp+=S[k][j];
                            n++;
                            break;
                        }
                    }
                    for (int k = j+1;k < C; k++) {
                        if (S[i][k]!=0) {
                            tmp+=S[i][k];
                            n++;
                            break;
                        }
                    }
                    for (int k = j-1;k >= 0; k--) {
                        if (S[i][k]!=0) {
                            tmp+=S[i][k];
                            n++;
                            break;
                        }
                    }
                    if (n > 0 && S[i][j] < tmp/n) {
                        rem.push_back(make_pair(i,j));
                    } 
                }
            } 
        }
        for (auto a : rem) {
            S[a.first][a.second]=0;
        }
        loop = rem.size()>0;
    } while (loop);
    cout << ans << endl;
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
