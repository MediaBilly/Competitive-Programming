#include <bits/stdc++.h>

using namespace std;

int cnt['k'-'a'+1]['k'-'a'+1];

char grid[100000][2];

void solve() {
    int n;
    cin >> n;
    string s;
    char c1, c2;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cin >> c1;
        cin >> c2;
        cnt[c1-'a'][c2-'a']++;
        grid[i][0] = c1;
        grid[i][1] = c2;
    }
    long long ans = 0;
    for (int i=0;i < n;i++) {
        for (char c = 'a';c <= 'k';c++) {
            if (c != grid[i][0]) {
                ans += cnt[c-'a'][grid[i][1]-'a'];
            }
        }
        for (char c = 'a';c <= 'k';c++) {
            if (c != grid[i][1]) {
                ans += cnt[grid[i][0]-'a'][c-'a'];
            }
        }
        cnt[grid[i][0]-'a'][grid[i][1]-'a']--;
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
