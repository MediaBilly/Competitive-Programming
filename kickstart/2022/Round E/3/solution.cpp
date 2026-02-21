#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    for (int i=0;i<s.length();i++) {
        if (s[i]!=s[s.length()-i-1]) {
            return false;
        }
    }
    return true;
}

void solve(int x) {
    int N;
    cin >> N;
    string P;
    cin >> P;
    int i=0;
    string Q(1,P[i]);
    while (!isPalindrome(P+Q) || !isPalindrome(Q)) {
        // cout << Q << endl;
        Q = P[++i] + Q;
    }
    cout << "Case #" << x << ": " << Q << endl;
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
