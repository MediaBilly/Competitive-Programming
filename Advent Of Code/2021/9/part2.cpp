#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& grid, set<pair<int, int>>& visited, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || visited.find(make_pair(i, j)) != visited.end() || grid[i][j]==9) {
        return;
    }
    visited.insert(make_pair(i, j));
    dfs(grid, visited, i-1, j);
    dfs(grid, visited, i+1, j);
    dfs(grid, visited, i, j-1);
    dfs(grid, visited, i, j+1);
}

int main(int argc,char *args[]) {
    vector<vector<int>> grid;
    string line;
    while (getline(cin, line)) {
        vector<int> row;
        for (char c: line) {
            row.push_back((int)(c-'0'));
        }
        grid.push_back(row);
    }

    int b1 = 0, b2 = 0, b3 = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0;j < grid[i].size();j++) {
            bool low = true;
            if (j > 0 && grid[i][j-1] <= grid[i][j]) {
                low = false;
            } else if (j < grid[i].size()-1 && grid[i][j+1] <= grid[i][j]) {
                low = false;
            } else if (i > 0 && grid[i-1][j] <= grid[i][j]) {
                low = false;
            } else if (i < grid.size()-1 && grid[i+1][j] <= grid[i][j]) {
                low = false;
            }
            if (low) {
                set<pair<int, int>> vis;
                dfs(grid, vis, i, j);
                if (vis.size() > b1) {
                    b3 = b2;
                    b2 = b1;
                    b1 = vis.size();
                } else if (vis.size() > b2) {
                    b3 = b2;
                    b2 = vis.size();
                } else if (vis.size() > b3) {
                    b3 = vis.size();
                }
            }
        }
    }
    cout << b1 * b2 * b3 << endl;
    
    return 0;
}