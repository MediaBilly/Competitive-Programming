#include <bits/stdc++.h>

using namespace std;

int N;
char board[100][100];
bool vis[100][100];

#define BLUE 'B'
#define RED 'R'

bool wins(char player, int i, int j) {
    vis[i][j] = true;
    if (player == BLUE && j == N-1) {
        return true;
    }
    if (player == RED && i == N-1) {
        return true;
    }
    if (i > 0 && board[i-1][j] == player && !vis[i-1][j]) {
        if (wins(player, i-1, j)) {
            return true;
        }
    }
    if (i < N-1 && board[i+1][j] == player && !vis[i+1][j]) {
        if (wins(player, i+1, j)) {
            return true;
        }
    }
    if (j > 0 && board[i][j-1] == player && !vis[i][j-1]) {
        if (wins(player, i, j-1)) {
            return true;
        }
    }
    if (j < N-1 && board[i][j+1] == player && !vis[i][j+1]) {
        if (wins(player, i, j+1)) {
            return true;
        }
    }
    if (i > 0 && j < N-1 && board[i-1][j+1] == player && !vis[i-1][j+1]) {
        if (wins(player, i-1, j+1)) {
            return true;
        }
    }
    if (i < N-1 && j > 0 && board[i+1][j-1] == player && !vis[i+1][j-1]) {
        if (wins(player, i+1, j-1)) {
            return true;
        }
    }
    return false;
}

bool blue_wins() {
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) {
        if (board[i][0] == BLUE && wins(BLUE, i, 0)) {
            return true;
        }
    }
    return false;
}

bool red_wins() {
    memset(vis, false, sizeof(vis));
    for (int j = 0;j < N;j++) {
        if (board[0][j] == RED && wins(RED, 0, j)) {
            return true;
        }
    }
    return false;
}

void solve(int x) {
    cin >> N;
    int blues = 0, reds = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0;j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                blues++;
            } else if (board[i][j] == 'R') {
                reds++;
            }
        }
    }
    string ans = "";
    if (abs(blues - reds) > 1) {
        ans = "Impossible";
    }

    if (ans == "") {
        if (blue_wins()) {
            if (blues >= reds) {
                bool ok = false;
                for (int i = 0;!ok && i < N; i++) {
                    for (int j = 0;!ok && j < N; j++) {
                        if (board[i][j] == BLUE) {
                            board[i][j] = '.';
                            if (!blue_wins()) {
                                ok = true;
                            }
                            board[i][j] = BLUE;
                        }
                    }
                }
                ans = ok ? "Blue wins" : "Impossible";
            } else {
                ans = "Impossible";
            }
        } else {
            if (red_wins()) {
                if (reds >= blues) {
                    bool ok = false;
                    for (int i = 0;!ok && i < N; i++) {
                        for (int j = 0;!ok && j < N; j++) {
                            if (board[i][j] == RED) {
                                board[i][j] = '.';
                                if (!red_wins()) {
                                    ok = true;
                                }
                                board[i][j] = RED;
                            }
                        }
                    }
                    ans = ok ? "Red wins" : "Impossible";
                } else {
                    ans = "Impossible";
                }
            } else {
                ans = "Nobody wins";
            }
        }
    }
    
    cout << "Case #" << x << ": " << ans << endl;
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
