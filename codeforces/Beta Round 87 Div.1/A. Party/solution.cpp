#include <bits/stdc++.h>

using namespace std;

int im[2000],h[2000];
bool visited[2000];

int dfs(int i) {
    if (visited[i]) {
        return h[i];
    } else {
        visited[i] = true;
        if (im[i] != -1) {
            h[i] = dfs(im[i])+1;
        } else {
            h[i]=1;
        }
        return h[i];
    }
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,p;
    cin >> n;
    memset(im,-1,sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p != -1) {
            im[i] = p-1;
        }
    }
    memset(h,0,sizeof(int) * n);
    memset(visited,false,sizeof(bool) * n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans,dfs(i));
    }
    cout << ans << endl;
    return 0;
}
