#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    string N;
    cin >> N;
    string ans = "";
    int digSum = 0;
    for (char c: N) {
        digSum += (c - '0');
    }
    int modDiff = (9 - digSum % 9) % 9;
    for(int i = 0;i <= N.length();i++) {
        string num = N;
        char d = modDiff + '0';
        if (i == 0 && d == '0') {
            continue;
        }
        num.insert(i, 1, d);
        // cout << num << endl;
        if (ans == "")
            ans = num;
        else {
            if (num < ans) {
                ans = num;
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
