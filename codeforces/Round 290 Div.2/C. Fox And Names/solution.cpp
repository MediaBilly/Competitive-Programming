#include <bits/stdc++.h>

using namespace std;

unordered_set<int> adj['z' - 'a' + 1];
bool visited['z' - 'a' + 1];
vector<char> ans;

void toposort(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            toposort(v);
        }
    }
    visited[u] = true;
    ans.push_back(u);
}

bool hasPath(int u, int v) {
    if (u == v) {
        return true;
    }
    for (int i : adj[u]) {
        if (hasPath(i,v)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    vector<string> strs;
    for (int i = 1;i <= n;i++) {
        cin >> str;
        strs.push_back(str);
    }
    memset(visited,false,sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int k=0;
            while(k < strs[i].length() && k < strs[j].length() && strs[i][k] == strs[j][k]) {
                k++;
            }
            if (k < strs[i].length() && k < strs[j].length()) {
                if (!hasPath(strs[j][k] - 'a',strs[i][k] - 'a')) {
                    adj[strs[i][k] - 'a'].insert(strs[j][k] - 'a');
                } else {
                    cout << "Impossible" << endl;
                    return 0;
                }
            } else if (strs[i].length() > strs[j].length()) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        if (!visited[i]) {
            toposort(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << (char)(ans[i] + 'a');
    }
    cout << endl;
    return 0;
}
