#include <bits/stdc++.h>

using namespace std;

typedef struct {
    bool isPostOffice;
    int mTime;
} Tile;

Tile grid[250][250];
bool visited[250][250];
int R,C;

int initial() {
    queue<pair<int,int>> q;
    pair<int,int> po;
    memset(visited,false,sizeof(visited));
    for (int i=0;i<R;i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j].isPostOffice) {
                grid[i][j].mTime=0;
                visited[i][j]=true;
                po.first=i;po.second=j;
                q.push(po);
            } else {
                grid[i][j].mTime=INT_MAX;
            }
        }
    }
    int ret = 0;
    while (q.size()>0) {
        for (int i = -1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                if (i != 0 ^ j != 0) {
                    po.first = q.front().first+i;
                    po.second = q.front().second+j;
                    if (po.first>=0 && po.first<R && po.second>=0 && po.second<C) {
                        grid[po.first][po.second].mTime=min(grid[po.first][po.second].mTime,grid[q.front().first][q.front().second].mTime+1);
                        if (!visited[po.first][po.second]) {
                            visited[po.first][po.second]=true;
                            ret=max(ret,grid[po.first][po.second].mTime);
                            q.push(po);
                        }
                    }
                }
            }
        }
        q.pop();
    }
    return ret;
}

bool test(int K) {
    int max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX,d;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j].mTime > K) {
                max1=max(max1,i+j);
                max2=max(max2,i-j);
                min1=min(min1,i+j);
                min2=min(min2,i-j);
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j].mTime > 0 && max(max(abs(max1-(i+j)),abs(max2-(i-j))),max(abs(min1-(i+j)),abs(min2-(i-j)))) <= K) {
                return true;
            }
        }
    }
    return false;
}

void solve(int x) {
    string s;
    cin >> R >> C;
    memset(grid,0,sizeof(grid));
    for (int i = 0;i<R;i++) {
        cin >> s;
        for (int j = 0;j<C;j++) {
            grid[i][j].isPostOffice = (s[j]=='1');
            grid[i][j].mTime = INT_MAX;
        }
    }
    int l=0,r=initial(),mid;
    while (l<r) {
        mid = l + (r-l)/2;
        if (!test(mid)) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    cout << "Case #" << x << ": " << l << endl;
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
