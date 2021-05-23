#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int ans = 0;

bool isPalindrome(string s) {
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-1-i]) {
            return false;
        }
    }
    return true;
}

void testSubStr(string target,string prefix, int k, int n) {
    if (n == 0) {
        if (isPalindrome(prefix) && prefix < target) {
            ans = (ans + 1) % M;
        }
        return;
    }
 
    for (int i = 0; i < k; i++) {
        string newPrefix;
         
        newPrefix = prefix;
        newPrefix += ('a' + i);
         
        testSubStr(target,newPrefix, k, n - 1);
    }
}

void solve(int x) {
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    ans = 0;
    testSubStr(S,"",K,N);
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
