#include <bits/stdc++.h>

using namespace std;

int stepCost[99];

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

void solve(int x) {
    int N,C;
    cin >> N >> C;
    vector<int> L;
    for (int i = 0; i < N; i++) {
        L.push_back(i+1);
    }
    if (C < N-1 || C > N*(N+1)/2 - 1) {
        cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
        return;
    }
    memset(stepCost,0,sizeof(stepCost));
    for (int i = 0; i < N-1; i++) {
        stepCost[i] = N - i;
    }
    int c = N*(N+1)/2 - 1;
    for (int i = N - 2; i >= 0 && c > C; i--) {
        while (c > C && stepCost[i] > 1) {
            stepCost[i]--;
            c--;
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        int j = i + stepCost[i]-1;
        my_reverse(L,i,j);
    }
    cout << "Case #" << x << ": ";
    for (int i = 0; i < N; i++) {
        cout << L[i] << " ";
    }
    cout << endl;
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
