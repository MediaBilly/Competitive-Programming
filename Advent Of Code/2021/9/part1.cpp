#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

    int ans = 0;
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
                ans+=grid[i][j]+1;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}