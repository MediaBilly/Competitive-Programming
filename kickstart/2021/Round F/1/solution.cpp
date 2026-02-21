#include <bits/stdc++.h>

using namespace std;

bool hasBin[500000];
int closest[500000];

void solve(int x) {
    int N;
    cin >> N;
    char c;
    memset(hasBin,false,sizeof(hasBin));
    memset(closest,-1,sizeof(closest));
    for (int i=0;i <N;i++) {
        cin >> c;
        if (c == '1') {
            hasBin[i] = true;
            closest[i]=i;
        }
    }
    int s=0,e=N-1;
    while (s<N-1&&!hasBin[s]) {
        s++;
    }
    while (e>0&&!hasBin[e]) {
        e--;
    }
    int curBin = s;
    for (int i = s; i <= e; i++) {
        if (hasBin[i]) {
            curBin = i;
        } else {
            closest[i] = curBin;
        }
    }
    curBin = e;
    for (int i = e; i >= s; i--) {
        if (hasBin[i]) {
            curBin = i;
        } else {
            if (abs(curBin-i) < abs(i-closest[i])) {
                closest[i] = curBin;
            }
        }
    }
    for (int i = 0; i < s; i++) {
        closest[i] = s;
    }
    for (int i = N-1; i > e; i--) {
        closest[i] = e;
    }
    
    
    unsigned long long ans = 0;
    for (int i=0;i<N;i++) {
        ans+=abs(i-closest[i]);
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
