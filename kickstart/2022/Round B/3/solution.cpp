#include <bits/stdc++.h>

using namespace std;

int N, D;
int locknum[400];

int mem[10][400][400];

int minmoves(int goal, int s, int e) {
    if (mem[goal][s][e] != -1) {
        return mem[goal][s][e];
    }
    // cout << s << ' ' << e << endl;
    int f = locknum[s];
    if (s == e) {
        // return abs(goal - f);
        mem[goal][s][e] = min((goal-f+D)%D, (f-goal+D)%D);
        return mem[goal][s][e];
    }
    int ret = INT_MAX;
    
    int tmp = 0;
    int l = s;
    while (l < N && locknum[l] == f) {
        l++;
    }
    int r = e;
    while (r >= l && locknum[r] == f) {
        r--;
    }
    tmp += (l <= r) ? minmoves(f, l, r) : 0;
    tmp += min((goal-f+D)%D, (f-goal+D)%D);
    ret = min(ret, tmp);

    tmp = 0;
    f = locknum[e];
    r = e;
    while (r >= 0 && locknum[r] == f) {
        r--;
    }
    l = s;
    while (l <= r && locknum[l] == f) {
        l++;
    }
    tmp += (l <= r) ? minmoves(f, l, r) : 0;
    tmp += min((goal-f+D)%D, (f-goal+D)%D);
    ret = min(ret, tmp);

    mem[goal][s][e] = ret;
    return ret;
}

void solve(int x) {
    cin >> N >> D;
    for (int i=0;i < N;i++) {
        cin >> locknum[i];
    }
    memset(mem, -1, sizeof(mem));
    cout << "Case #" << x << ": " << minmoves(0, 0, N-1) << endl;
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
