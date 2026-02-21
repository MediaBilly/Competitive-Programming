#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int grid[500][500];
int cost[500][500];

class Compare {
    public:
        bool operator()(pair<int, int> const& s1, pair<int, int> const& s2) {
            return cost[s1.first][s1.second] > cost[s2.first][s2.second];
        }
};

int main() {
    string line;
    int i=0,j=0,m,n;
    while (getline(cin, line)) {
        m = line.length();
        j=0;
        for (char c: line) {
            grid[i][j]=(int)(c - '0');
            cost[i][j] = INT32_MAX;
            for (int k = 1;k <= 4;k++) {
                grid[i][m *k + j] = grid[m * k + i][j] = grid[i][m * (k-1) + j] % 9 + 1;
                cost[i][m *k + j] = cost[m * k + i][j] = INT32_MAX;
            }
            j++;
        }
        n = ++i;
    }

    for (int kn = 1;kn <= 4;kn++) {
        for (i = 0; i < n; i++) {
            for (int km = 1;km <= 4;km++) {
                for (j = 0;j < m;j++) {
                    grid[n * kn + i][m * km + j] = grid[n * kn + i][m * (km - 1) + j] % 9 + 1;
                    cost[n * kn + i][m * km + j] = INT32_MAX;
                }
            }
        }
    }

    n *= 5;
    m *= 5;

    // for (i = 0; i < n; i++) {
    //     for (j = 0;j < m;j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    q.push(make_pair(0, 0));
    cost[0][0] = 0;
    while (!q.empty()) {
        pair<int, int> u = q.top();
        q.pop();
        // left
        if (u.second > 0 && cost[u.first][u.second] + grid[u.first][u.second-1] < cost[u.first][u.second-1]) {
            cost[u.first][u.second-1] = cost[u.first][u.second] + grid[u.first][u.second-1];
            q.push(make_pair(u.first, u.second-1));
        }
        // right
        if (u.second < m && cost[u.first][u.second] + grid[u.first][u.second+1] < cost[u.first][u.second+1]) {
            cost[u.first][u.second+1] = cost[u.first][u.second] + grid[u.first][u.second+1];
            q.push(make_pair(u.first, u.second+1));
        }
        // up
        if (u.first > 0 && cost[u.first][u.second] + grid[u.first-1][u.second] < cost[u.first-1][u.second]) {
            cost[u.first-1][u.second] = cost[u.first][u.second] + grid[u.first-1][u.second];
            q.push(make_pair(u.first-1, u.second));
        }
        // down
        if (u.first < n && cost[u.first][u.second] + grid[u.first+1][u.second] < cost[u.first+1][u.second]) {
            cost[u.first+1][u.second] = cost[u.first][u.second] + grid[u.first+1][u.second];
            q.push(make_pair(u.first+1, u.second));
        }
    }
    

    // for (i = 0; i < n; i++) {
    //     for (j = 0;j < m;j++) {
    //         cout << cost[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << cost[n-1][m-1] << endl;
    
    return 0;
}