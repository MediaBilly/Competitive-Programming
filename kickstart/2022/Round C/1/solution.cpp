#include <bits/stdc++.h>

using namespace std;

unordered_set<char> special = { '#', '@', '*', '&'};

void solve(int x) {
    int N;
    cin >> N;
    string oldPass;
    cin >> oldPass;
    bool hasLowercase = false, hasUppercase = false, hasDigit = false, hasSpecial = false;
    for (int i=0;i<oldPass.length();i++) {
        if (oldPass[i] >= 'a' && oldPass[i] <= 'z') {
            hasLowercase = true;
        }
        else if (oldPass[i] >= 'A' && oldPass[i] <= 'Z') {
            hasUppercase = true;
        }
        else if (oldPass[i] >= '0' && oldPass[i] <= '9') {
            hasDigit = true;
        }
        else if (special.find(oldPass[i]) != special.end()) {
            hasSpecial = true;
        }
    }
    string ans = oldPass;
    if (!hasLowercase) {
        ans += 'a';
    }
    if (!hasUppercase) {
        ans += 'A';
    }
    if (!hasDigit) {
        ans += '0';
    }
    if (!hasSpecial) {
        ans += '@';
    }
    int len = ans.length();
    for (int i=len;i<7;i++) {
        ans += '1';
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
