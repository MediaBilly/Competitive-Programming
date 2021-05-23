#include <bits/stdc++.h>

using namespace std;

unsigned long long b[200002];
// int sum[200002];

int binarySearch(int l, int r, unsigned long long x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        if (b[mid] == x)
            return mid;
        if (b[mid] > x)
            return binarySearch(l, mid - 1, x);
        return binarySearch(mid + 1, r, x);
    }
    return -1;
}

void solve() {
    int n;
    cin >>n;
    unsigned long long sum=0;
    for (int i = 0; i < n+2; i++) {
        cin >> b[i];
        sum +=b[i];
    }
    sort(b,b+n+2);
    for (int x = 0; x < n+2; x++) {
        unsigned long long diff = sum - 2 * b[x];
        int diffpos = binarySearch(0,x-1,diff);
        if (diffpos == -1) {
            diffpos = binarySearch(x+1,n+1,diff);
        }
        if (diffpos != -1) {
            for (int i = 0; i < n+2; i++) {
                if (diffpos != i && i != x) {
                    cout << b[i] << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    
    cout << -1 << endl;
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
