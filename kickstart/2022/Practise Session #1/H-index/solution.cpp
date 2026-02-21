#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    vector<int> ans;
    int N,ci;
    cin >> N;
    vector<int> C;
    for (int i=0;i<N;i++) {
        cin >> ci;
        C.push_back(ci);
    }
    cout << "Case #" << x << ": ";
    priority_queue<int, vector<int>, greater<int>> frontier;
    for (int i = 0, hIndex=0; i < N; i++) {
        if (C[i] >= hIndex+1) {
            frontier.push(C[i]);
        }
        if (frontier.size() == hIndex+1) {
            hIndex++;
            while (!frontier.empty() && frontier.top() < hIndex+1) {
                frontier.pop();
            }
            
        }
        cout << hIndex << ' ';
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
