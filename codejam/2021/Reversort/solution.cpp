#include <bits/stdc++.h>

using namespace std;

void my_reverse(vector<int> &L,int i,int j) {
    int tmp;
    for (; i <= j;) {
        tmp = L[i];
        L[i] = L[j];
        L[j] = tmp;
        i++;
        j--;
    }
}

void solve(int x) {
    int N,Li;
    cin >> N;
    vector<int> L;
    for (int i = 0; i < N; i++) {
        cin >> Li;
        L.push_back(Li);
    }
    int ans = 0;
    for (int i = 0; i < L.size()-1; i++) {
        int j=i,m=L[i];
        for (int k = j+1; k < L.size(); k++) {
            if (L[k] < L[j]) {
                j = k;
                m = L[k];
            }
        }
        ans += j - i + 1;
        my_reverse(L,i,j);
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
