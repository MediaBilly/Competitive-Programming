#include <bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int dist[1000][1000];
int N,M,K;

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            dist[i][j] = INT_MAX;
        }
    }
    int X,Y;
    vector<pair<int,int>> special;
    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        special.push_back(make_pair(X-1,Y-1));
    }
    vector<pair<int,int>> delta = {make_pair(-1,0),make_pair(0,-1),make_pair(1,0),make_pair(0,1)};
    for (int i = 0; i < K; i++) {
        queue<pair<int,int>> q;
        q.push(special[i]);
        dist[special[i].first][special[i].second] = 0;
        while (!q.empty()) {
            pair<int,int> u = q.front();
            q.pop();
            for (pair<int,int> d : delta) {
                int vx = u.first+d.first,vy=u.second+d.second;
                if (vx >= 0 && vy >= 0 && vx < N && vy < M && dist[vx][vy] > dist[u.first][u.second]+1 && grid[vx][vy] == '.') {
                    q.push(make_pair(vx,vy));
                    dist[vx][vy] = dist[u.first][u.second]+1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.') {
                ans += dist[i][j];
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}