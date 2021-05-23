#include <bits/stdc++.h>

using namespace std;

int P[100];

void solve() {
    int M,Pi,Ni,N=0;
    cin >> M;
    unsigned long long pr=1;
    int ptr=0;
    for (int i = 0; i < M; i++) {
        cin >> Pi >> Ni;
        for (int j = 0; j < Ni; j++) {
            P[ptr++]=Pi;
        }
        pr *= P[i];
        N+=Ni;
    }
    unsigned long long maxScore = 0;
    int p1=0,p2=1;
    pr/=P[0];
    unsigned long long s=P[0];
    while (p1<N&&p2<N) {
        if (s==pr) {
            maxScore=max(s,maxScore);
            pr*=P[p1];
            s-=P[p1++];
            p2=p1;
        }
    }
    
    cout << maxScore << endl;
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
