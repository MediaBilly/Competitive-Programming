#include <bits/stdc++.h>

using namespace std;

int N,K;
int mat[50][50];

// bool test() {

// }

bool nextTrace() {
    int i=N-2;
    if (mat[i][i]+1>N) {
        i--;
    } else {

    }
}

void solve(int x) {
    cin >> N >> K;
    int ans = 0;
    int tr = K,trace=0;
    memset(mat,0,sizeof(mat));
    for (int i = 0; i < N; i++) {
        if (tr - K/N >= 0) {
            mat[i][i]=K/N;
        } else if (i == N-1) {
            mat[i][i]=K % N;
        }
        trace+=mat[i][j];
    }
    for (int i = 0; i < N; i++) {
        cout << mat[i][i] << " ";
    }
    
    cout << endl;
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
