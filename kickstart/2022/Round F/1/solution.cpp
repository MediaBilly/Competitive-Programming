#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
    string C;
    int D;
    int U;
} fabric;

bool cmp1(fabric &f1, fabric &f2) {
    return f1.C < f2.C || f1.C == f2.C && f1.U < f2.U;
}

bool cmp2(fabric &f1, fabric &f2) {
    return f1.D < f2.D || f1.D == f2.D && f1.U < f2.U;
}


void solve(int x) {
    int N;
    cin >> N;
    vector<fabric> f1, f2;
    fabric f;
    for (int i=0;i<N;i++) {
        cin >> f.C >> f.D >> f.U;
        f1.push_back(f);
        f2.push_back(f);
    }
    sort(f1.begin(), f1.end(), cmp1);
    sort(f2.begin(), f2.end(), cmp2);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        // cout << f1[i].C << " " << f1[i].D << ' ' << f1[i].U << endl;
        // cout << f2[i].C << " " << f2[i].D << ' ' << f2[i].U << endl;
        // cout << endl;
        ans += (f1[i].U == f2[i].U);
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
