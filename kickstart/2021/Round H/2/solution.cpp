#include <bits/stdc++.h>

using namespace std;
bool R[100001], Y[100001], B[100001];

void solve(int x) {
    int N;
    char c;
    cin >> N;
    memset(R, false, sizeof(R));
    memset(Y, false, sizeof(Y));
    memset(B, false, sizeof(B));
    for (int i = 0; i < N; i++) {
        cin >> c;
        switch (c)
        {
            case 'R':
                R[i]=true;
                break;
            case 'B':
                B[i]=true;
                break;
            case 'Y':
                Y[i]=true;
                break;
            case 'O':
                R[i]=true;
                Y[i]=true;
                break;
            case 'P':
                R[i]=true;
                B[i]=true;
                break;
            case 'G':
                Y[i]=true;
                B[i]=true;
                break;
            case 'A':
                R[i]=true;
                B[i]=true;
                Y[i]=true;
            default:
                break;
        }
    }
    
    int ans = 0;

    // Red strokes
    bool on = false;
    for (int i = 0; i < N; i++) {
        if (R[i]) {
            if (!on) {
                on = true;
                ans++;
            }
        } else {
            if (on) {
                on = false;
            }
        }
    }
    // Blue strokes
    on = false;
    for (int i = 0; i < N; i++) {
        if (B[i]) {
            if (!on) {
                on = true;
                ans++;
            }
        } else {
            if (on) {
                on = false;
            }
        }
    }
    // Yellow strokes
    on = false;
    for (int i = 0; i < N; i++) {
        if (Y[i]) {
            if (!on) {
                on = true;
                ans++;
            }
        } else {
            if (on) {
                on = false;
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
