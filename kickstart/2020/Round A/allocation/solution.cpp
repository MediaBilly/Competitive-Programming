#include <bits/stdc++.h>

using namespace std;

int A[100000];

void solve(int x) {
    int N,B,y=0;
    cin >> N >> B;
    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }
    sort(A,A+N);
    while (y < N && B >= A[y]) {
        B -= A[y++];
    }
    cout << "Case #" << x << ": " << y << endl;
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
