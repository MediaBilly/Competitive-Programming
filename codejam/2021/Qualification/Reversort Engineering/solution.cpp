#include <bits/stdc++.h>

using namespace std;

void swap(vector<int> &L,int i,int j) {
    int tmp;
    tmp = L[i];
    L[i] = L[j];
    L[j] = tmp;
}

void my_reverse(vector<int> &L,int i,int j) {
    int tmp;
    for (; i <= j;) {
        swap(L,i,j);
        i++;
        j--;
    }
}

int calc_cost(vector<int> L) {
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
    return ans;
}

void solve(int x) {
    int N,C;
    cin >> N >> C;
    vector<int> L;
    for (int i = 0; i < N; i++) {
        L.push_back(i+1);
    }

    int cost = calc_cost(L);
    sort(L.begin(),L.end());
    while (cost != C && next_permutation(L.begin(),L.end())) {
        cost = calc_cost(L);
    }
    if (cost ==C) {
        cout << "Case #" << x << ": ";
        for (int i = 0; i < N; i++) {
            cout << L[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
    }
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
