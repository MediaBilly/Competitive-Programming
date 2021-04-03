#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int A,B,N;
    cin >> A >> B >> N;
    A++;
    int mid;
    string res;
    while (N--) {
        mid = A + (B - A)/2;
        cout << mid << endl;
        fflush(stdout);
        cin >> res;
        if (res == "CORRECT") {
            return;
        } else if (res == "TOO_SMALL") {
            A = mid + 1;
        } else if (res == "TOO_BIG") {
            B = mid - 1;
        }
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
