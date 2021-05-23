#include <bits/stdc++.h>

using namespace std;

int g[2000000001][2000000001],f[2000000001][2000000001];

typedef struct 
{
    int x,y;
    int prevX,prevY;
    char action;
} state;

struct Cmp {
    bool operator()(state const& s1, state const& s2) {
        return s1.g + s1.h < s2.g + s2.h;
    }
};

int dist(int x1,int x2,int y1,int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    int X,Y;
    cin >> X >> Y;
    priority_queue<state,vector<state>,Cmp> queue;
    state s;
    s.x = s.y = 0;
    s.g = 0;
    s.h = dist(0,X,0,Y);
    queue.push(s);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
