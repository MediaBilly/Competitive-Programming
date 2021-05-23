#include <bits/stdc++.h>

using namespace std;

char grid[30][30];
bool visited['Z' - 'A' + 1];
bool current['Z' - 'A'+1];
int R,C;

unordered_map<char,unordered_set<char>> adj;

vector<char> ans;

bool toposort(char u) {
    visited[u - 'A'] = true;
    current[u - 'A'] = true;
    for (char v : adj[u]) {
        if (current[v - 'A']) {
            return false;
        } else if (!visited[v - 'A']) {
            if (!toposort(v)) {
                return false;
            }
        }
    }
    current[u - 'A'] = false;
    ans.push_back(u);
    return true;
}

void solve(int x) {
    adj.clear();
    ans.clear();
    cin >> R >> C;
    unordered_set<char> trms;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            trms.insert(grid[i][j]);
        }
    }
    cout << "Case #" << x << ": ";
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i-1][j] != grid[i][j]) {
                adj[grid[i-1][j]].insert(grid[i][j]);
            }
        }
    }
    memset(visited,false,sizeof(visited));
    memset(current,false,sizeof(current));
    for (char i : trms) {
        if (!visited[i - 'A']) {
            if (!toposort(i)) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
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
