#include <bits/stdc++.h>

using namespace std;

int f[100001], p[100001];
long long dp[100001];
int dpmax[100001];
unordered_map<int, unordered_set<int>> children; // maps node id to a set of it's children
int N;

void dfs(int root) {
    if (children[root].size() > 0) {
        for (int child: children[root]) {
            dfs(child);
        }
        long long minChild = LONG_LONG_MAX;
        int minChildIdx = -1;
        dp[root] = 0;
        for (int child: children[root]) {
            if (dpmax[child] <= minChild) {
                minChild = dpmax[child];
                minChildIdx = child;
            }
        }
        for (int child: children[root]) {
            dp[root] += dp[child];
            if (child != minChildIdx) {
                dp[root] += dpmax[child];
            }
        }
        dpmax[root] = max(minChild, (long long)f[root]);
    } else {
        dp[root] = 0;
        dpmax[root] = f[root];
    }
}

void solve() {
    cin >> N;
    // Read graph info
    children.clear();
    memset(dp, -1, sizeof(dp));
    memset(dpmax, -1, sizeof(dpmax));
    for (int i = 1; i <= N; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        children[p[i]].insert(i);
    }
    // Calculate dp values
    for (int i=1;i<=N;i++) {
        // start from each tree's root
        if (p[i] == 0) {
            dfs(i);
        }
    }
    long long ans = 0;
    // Calculate total sum of every tree in the forest
    for (int i = 1; i <= N; i++) {
        // Consider roots only
        if (p[i] == 0) {
            ans += dp[i] + dpmax[i];
        }
    }
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
