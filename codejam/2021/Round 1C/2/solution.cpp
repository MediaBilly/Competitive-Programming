#include <bits/stdc++.h>

using namespace std;

bool roaring(string num,int prev=0) {
    if (num == "") {
        return true;
    }
    int tmp = 0;
    for (int i = 0;tmp <= prev && i < num.length(); i++) {
        tmp = 10 * tmp + (num[i] - '0');
        if (tmp == prev + 1) {
            return roaring(num.substr(i+1,num.length()-i-1),tmp);
        } else {
            return false;
        }
    }
    return false;
}

void solve() {
    
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
