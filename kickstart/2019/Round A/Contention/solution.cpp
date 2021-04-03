#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int L;
    int R;
} Query;

struct cmp {
    bool operator()(Query const& q1, Query const& q2) {
        return q1.R - q1.L > q2.R - q2.L;
    }
};

bool seat[1000000];
priority_queue<Query,vector<Query>,cmp> queries;

void solve(int x) {
    Query q;
    int N,Q;
    cin >> N >> Q;
    int ans = N,cnt;
    memset(seat,false,sizeof(seat));
    for (int i=0;i<Q;i++) {
        cin >> q.L >> q.R;
        queries.push(q);
    }
    for (int i=0;i<Q;i++) {
        q=queries.top();
        cnt=0;
        for (int j=q.L;j<=q.R;j++) {
            if (seat[j-1]==false) {
                seat[j-1]=true;
                cnt++;
            }
        }
        ans = min(ans,cnt);
        queries.pop();
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
