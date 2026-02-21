#include <bits/stdc++.h>

using namespace std;

#define DIR_LEFT 0
#define DIR_RIGHT 1

int L;
int P[100000], dir[100000];

bool fallen(int i) {
    return P[i] < 0 || P[i] > L;
}

void solve(int x) {
    int N;
    cin >> N >> L;
    for (int i=0;i<N;i++) {
        cin >> P[i] >> dir[i];
    }
    int alive = N;
    cout << "Case #" << x << ": ";
    while (alive > 0) {
        // Collision detection
        for (int i=0;i<N;i++) {
            for (int j=i;j<N;j++) {
                if (!fallen(i) && !fallen(j))
                    if (P[i] == P[j] || abs(P[i] - P[j]) == 1) {
                        int tmp = dir[i];
                        dir[i] = dir[j];
                        dir[j] = tmp;
                    }
            }
        }
        for (int i=0;i<N;i++) {
            if (!fallen(i)) {
                if (dir[i] == DIR_LEFT) {
                    P[i]--;
                } else {
                    P[i]++;
                }
                if (fallen(i)) {
                    cout << i+1 << ' ';
                    alive--;
                }
            }
        }
    }
    cout << endl;
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
