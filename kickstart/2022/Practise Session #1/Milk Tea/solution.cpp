#include <bits/stdc++.h>

#define MAXP 100

using namespace std;

void solve(int x) {
    int N,M,P;
    cin >> N >> M >> P;
    vector<bitset<MAXP>> prefs;
    unordered_set<bitset<MAXP>> constrains;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        prefs.push_back(bitset<MAXP>(s));
    }
    for (int i = 0; i < M; i++) {
        cin >> s;
        constrains.insert(bitset<MAXP>(s));
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < (1 << P); i++) {
        int complains = 0;
        bitset<MAXP> curType(i);
        if (constrains.find(curType) != constrains.end()) {
            continue;
        }
        for (auto p: prefs) {
            complains += (p ^ curType).count();
        }
        ans = min(ans, complains);
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
