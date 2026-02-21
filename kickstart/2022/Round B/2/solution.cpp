#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(long long num) {
    string strNum = to_string(num);
    int i=0,j=strNum.length()-1;
    while (i <= j) {
        if (strNum[i] != strNum[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(int x) {
    long long A;
    cin >> A;
    long long ans = 0;
    for (long long d = 1;d * d <= A;d++) {
        if (A % d == 0) {
            if (A/d == d) {
                if (isPalindrome(d)) {
                    ans++;
                } 
            } else {
                if (isPalindrome(d)) {
                    ans++;
                }
                if (isPalindrome(A/d)) {
                    ans++;
                }
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
