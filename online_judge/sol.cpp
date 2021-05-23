#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool removed[100];

void toposort(int u,stack<int> &s) {
    removed[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        if (!removed[adj[u][i]]) {
            toposort(adj[u][i],s);
        }
    }
    s.push(u);
}

int main(int argc, char const *argv[]) {
    int n,m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        int i,j;
        adj.clear();
        adj.resize(n);
        for (int k = 0; k < m; k++) {
            cin >> i >> j;
            adj[i-1].push_back(j-1);
        }
        memset(removed,false,n * sizeof(bool));
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!removed[i]) {
                toposort(i,s);
            }
        }
        while (!s.empty()) {
            cout << s.top()+1;
            s.pop();
            if (!s.empty()) {
                cout << " ";
            }
        }
        cout << endl;
        cin >> n >> m;
    }
    
    return 0;
}
