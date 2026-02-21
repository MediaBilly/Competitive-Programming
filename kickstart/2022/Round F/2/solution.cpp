#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int par;
    unordered_set<int> adj;
} node;

vector<node> tree;
unordered_map<int, int> nodes_by_level;
unordered_set<int> visited;

void dfs(int i, int level) {
    if (visited.find(i) != visited.end()) {
        return;
    }
    visited.insert(i);
    if (nodes_by_level.find(level) != nodes_by_level.end()) {
        nodes_by_level[level]++;
    } else {
        nodes_by_level[level]=1;
    }
    for (int c : tree[i].adj) {
        dfs(c, level+1);
    }
}


void solve(int x) {
    int N,Q;
    cin >> N >> Q;
    int i,j;
    // Init tree
    nodes_by_level.clear();
    visited.clear();
    tree.clear();
    tree.resize(N);
    for (int k = 0; k < N-1; k++) {
        cin >> i >> j;
        i--;j--;
        tree[i].adj.insert(j);
        tree[j].adj.insert(i);
    }
    int q;
    dfs(0, 0);
    int ans = 0;
    // Consume q input
    for (int k=0;k<Q;k++) {
        cin >> q;
    }
    int level = 0;
    while (level < nodes_by_level.size() && ans + nodes_by_level[level] <= Q) {
        ans += nodes_by_level[level++];
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
