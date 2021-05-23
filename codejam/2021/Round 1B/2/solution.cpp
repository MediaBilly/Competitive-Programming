#include <bits/stdc++.h>

using namespace std;

int U[21];

bool check(unordered_map<int,int32_t> &state) {
    for (unsigned int i = 1; i < state.size(); i++) {
        if (state.find(i) != state.end() && state[i] < U[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N,A,B;
    cin >> N >> A >> B;
    unordered_map<int,int> state;
    for (int i = 0; i < N; i++) {
        cin >> U[i+1];
    }
    for (int i = 1; i <= N; i++) {
        state.clear();
        state[i] = 1;
    }
    
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
