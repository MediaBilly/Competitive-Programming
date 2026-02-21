#include <bits/stdc++.h>

using namespace std;

char grid[1000][1000];

typedef struct {
    int row;
    int begin;
    int end;
} hor_word;

typedef struct {
    int col;
    int begin;
    int end;
} vert_word;

void solve(int x) {
    int N,M;
    cin >> N >> M;

    // Read grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Define horizontal words
    vector<hor_word> hor_words;
    for (int i = 0; i < N; i++) {
        int j=0;
        while (j < M) {
            while (j < M && grid[i][j] == '#') {
                j++;
            }
            if (j >= M) {
                break;
            }
            int begin = j++;
            while (j < M && grid[i][j] != '#') {
                j++;
            }
            int end = j-1;
            hor_word tmp = { i, begin, end };
            hor_words.push_back(tmp);
        }
    }

    // for (int i = 0; i < hor_words.size(); i++) {
    //     cout << hor_words[i].row << " " << hor_words[i].begin << " " << hor_words[i].end << endl;
    // }

    // Define vertical words
    vector<vert_word> vert_words;
    for (int i = 0; i < M; i++) {
        int j=0;
        while (j < N) {
            while (j < N && grid[j][i] == '#') {
                j++;
            }
            if (j >= N) {
                break;
            }
            int begin = j++;
            while (j < N && grid[j][i] != '#') {
                j++;
            }
            int end = j-1;
            vert_word tmp = { i, begin, end };
            vert_words.push_back(tmp);
        }
    }

    // cout << "---------------\n";

    // for (int i = 0; i < vert_words.size(); i++) {
    //     cout << vert_words[i].col << " " << vert_words[i].begin << " " << vert_words[i].end << endl;
    // }
    
    int ans = 0;
    bool changed = true;
    do {
        changed = false;
        // Horizontal
        for (int i = 0; i < hor_words.size(); i++) {
            for (int b = hor_words[i].begin, e = hor_words[i].end; b <= e;) {
                int row = hor_words[i].row;
                if (grid[row][b] == '.' && grid[row][e] != '.') {
                    grid[row][b] = grid[row][e];
                    changed = true;
                    ans++;
                } else if (grid[row][e] == '.' && grid[row][b] != '.') {
                    grid[row][e] = grid[row][b];
                    changed = true;
                    ans++;
                }
                b++;
                e--;
            }
        }

        // Vertical
        for (int i = 0; i < vert_words.size(); i++) {
            for (int b = vert_words[i].begin, e = vert_words[i].end; b <= e;) {
                int col = vert_words[i].col;
                if (grid[b][col] == '.' && grid[e][col] != '.') {
                    grid[b][col] = grid[e][col];
                    changed = true;
                    ans++;
                } else if (grid[e][col] == '.' && grid[b][col] != '.') {
                    grid[e][col] = grid[b][col];
                    changed = true;
                    ans++;
                }
                b++;
                e--;
            }
        }
        
    } while (changed);
    
    cout << "Case #" << x << ": " << ans << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
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
