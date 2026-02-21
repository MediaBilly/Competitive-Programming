#include <bits/stdc++.h>

using namespace std;

int p[200001];

void solve() {
    int n, root;
    cin >> n;
    unordered_set<int> leaves;
    unordered_map<int, int> maxpath, maxchild;
    for (int i = 1;i <= n;i++) {
        leaves.insert(i);
    }
    unordered_map<int, unordered_set<int>> children;
    for (int i = 1;i<=n;i++) {
        cin >> p[i];
        if (leaves.find(p[i]) != leaves.end()) {
            leaves.erase(p[i]);
        }
        if (p[i] != i)
            children[p[i]].insert(i);
        else
            root = i;
        maxpath[i] = 0;
        maxchild[i] = 0;
    }
    for (int l: leaves) {
        maxpath[l] = 1;
        maxchild[l] = 0;
        int i = l, par = p[i];
        while (par != i) {
            // maxpath[par] = max(maxpath[par], maxpath[i]+1);
            if (maxpath[i]+1 > maxpath[par]) {
                maxpath[par] = maxpath[i]+1;
                maxchild[par] = i;
            }
            i = par;
            par = p[i];
        }
    }

    queue<int> q;
    q.push(root);
    vector<vector<int>> paths;
    while (!q.empty()) {
        int r=q.front();
        q.pop();
        vector<int> path;
        while (r != 0) {
            path.push_back(r);
            for (int c: children[r]) {
                if (c != maxchild[r]) {
                    q.push(c);
                }
            }
            r = maxchild[r];
        }
        paths.push_back(path);
    }
    cout << paths.size() << endl;
    for (auto path: paths) {
        cout << path.size() << endl;
        for (int i: path) {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
