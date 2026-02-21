#include <bits/stdc++.h>

using namespace std;

int a[50];

int dist(string a, string b) {
    int ans = 0;
    for (int i=0;i<a.length();i++) {
        ans += abs(a[i] - b[i]);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> words;
    for (int i = 0;i < n;i++) {
        string w;
        cin >> w;
        words.push_back(w);
    }

    int ans=INT_MAX;
    for (int i =0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            ans = min(ans, dist(words[i], words[j]));
        }
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve();
    }
    return 0;
}
