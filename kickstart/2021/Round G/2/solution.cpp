#include <bits/stdc++.h>

using namespace std;


void solve(int x) {
    int K;
    cin >> K;
    int x1,y1,x2,y2;
    vector<int> px,py;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        px.push_back(x1);
        px.push_back(x2);
        py.push_back(y1);
        py.push_back(y2);
    }
    sort(px.begin(), px.end());
    sort(py.begin(), py.end());

    cout << "Case #" << x << ": " << px[K-1] << ' ' << py[K-1] << endl;
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
