#include <bits/stdc++.h>

using namespace std;

int n,k;
string str;

int mem[50][50];

int calc(int s,int e) {
    if (mem[s][e] != -1) {
        return mem[s][e];
    }
    if (str[s] == '*' && str[e] == '*' && e - s <= k) {
        if (mem[s][e] == -1) {
            mem[s][e] = 0;
        }
        return 0;
    }
    
    int ret = INT_MAX;
    for (int i = s+1;i <= e && i <= s+k; i++) {
        if (str[i] == '.') {
            continue;
        }
        ret = min(ret,calc(i,e));
    }

    for (int i = e-1;i >= s && i >= e-k; i--) {
        if (str[i] == '.') {
            continue;
        }
        ret = min(ret,calc(s,i));
    }
    
    if (mem[s][e]==-1) {
        mem[s][e] = ret+1;
    }
    return ret+1;
}

void solve() {
    cin >> n >> k;
    cin >> str;

    int start=0,end=n-1;
    while (start < n && str[start]=='.')
        start++;
    while (end >= 0 && str[end]=='.')
        end--;

    if (start == end) {
        cout << 1 << endl;
    } else {
        memset(mem,-1,sizeof(mem));
        cout << calc(start,end)+2 << endl;
    }
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
