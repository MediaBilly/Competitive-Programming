#include <iostream>
#include <string>

using namespace std;

int grid[100][100];
int cost[100][100];

int main() {
    string line;
    int i=0,j=0,m,n;
    while (getline(cin, line)) {
        j=0;
        for (char c: line) {
            grid[i][j]=(int)(c - '0');
            cost[i][j] = INT32_MAX;
            m = ++j;
        }
        n = ++i;
    }

    cost[0][0] = grid[0][0];
    for (i = 0; i < n; i++) {
        for (j=0;j<m;j++) {
            int mincost = cost[i][j];
            if (i > 0) {
                mincost = min(mincost, cost[i-1][j] + grid[i][j]);
            }
            if (j > 0) {
                mincost = min(mincost, cost[i][j-1] + grid[i][j]);
            }
            cost[i][j] = min(cost[i][j], mincost);
        }
    }
    cout << cost[n-1][m-1] - grid[0][0] << endl;
    
    return 0;
}