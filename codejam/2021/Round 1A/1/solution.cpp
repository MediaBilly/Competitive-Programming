#include <bits/stdc++.h>

using namespace std;

void inc(string& num) {
    int i = num.length() - 1;
    while (i >= 0 && num[i] == '9') {
        num[i--] = '0';
    }
    if (i >= 0) {
        num[i]++;
    } else {
        num.insert(num.begin(), '0');
    }
}

bool gt(string a, string b) {
    if (a.length() < b.length()) {
        return false;
    } else if (a.length() > b.length()) {
        return true;
    }
    return a > b;
}

void solve() {
    int N;
    cin >> N;
    string numStr, prevNumStr = "";
    int ans=0;
    for (int i = 0; i < N; i++) {
        cin >> numStr;
        if (i > 0) {
            if (gt(prevNumStr, numStr) || prevNumStr == numStr) {
                if (prevNumStr.length() == numStr.length()) {
                    numStr += "0";
                    ans += 1;
                } else {
                    int k = prevNumStr.length() - numStr.length();
                    string tmpNumStr = numStr;
                    for (int j=0;j<k;j++) {
                        tmpNumStr += "0";
                    }
                    if (gt(tmpNumStr, prevNumStr)) {
                        numStr = tmpNumStr;
                        ans += k;
                    } else {
                        tmpNumStr = numStr;
                        for (int j=0;j<k;j++) {
                            tmpNumStr += "9";
                        }
                        if (!gt(tmpNumStr, prevNumStr)) {
                            tmpNumStr = numStr;
                            for (int j=0;j<k+1;j++) {
                                tmpNumStr += "0";
                            }
                            numStr = tmpNumStr;
                            ans += k+1;
                        } else {
                            inc(prevNumStr);
                            numStr = prevNumStr;
                            ans += k;
                        }
                    }
                }
            }
        }
        // cerr << numStr << endl;
        prevNumStr = numStr;
    }
    cout << ans << endl;
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
