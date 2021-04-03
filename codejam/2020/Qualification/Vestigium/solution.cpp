#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool seen[101];

void solve(int x) {
    int N,k=0,r=0,c=0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (i == j) {
                k+=arr[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        memset(seen,false,sizeof(seen));
        for (int j = 0; j < N; j++) {
            if (seen[arr[i][j]]) {
                r++;
                break;
            } else {
                seen[arr[i][j]]=true;
            }
        }
    }
    

    for (int j = 0; j < N; j++) {
        memset(seen,false,sizeof(seen));
        for (int i = 0; i < N; i++) {
            if (seen[arr[i][j]]) {
                c++;
                break;
            } else {
                seen[arr[i][j]]=true;
            }
        }
    }
    
    
    cout << "Case #" << x << ": " << k << " " << r << " " << c << endl;
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
