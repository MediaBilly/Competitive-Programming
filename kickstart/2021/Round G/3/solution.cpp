#include <bits/stdc++.h>

using namespace std;

int B[5000];

int smallestKsumSubarray(int start, int N, int K) {
    while (start < N && B[start] == 0){
        start++;
    }
    
    int s = 0, st = start;
    int len = INT_MAX;
    for (int i = start; i < N && st < N;) {
        if (s + B[i] < K) {
            s+=B[i++];
        } else if (s + B[i] == K) {
            s = 0;
            len = min(len, i - st + 1);
            st = ++i;
        } else {
            s-=B[st++];
        }
    }
    if (len > N - start) {
        return -1;
    }
    return len;
}

void solve(int x) {
    int N,K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    
    int ans = INT_MAX;
    // cout << ans << endl;
    int s;
    for (int j = N-1; j >= 0; j--) {
        s = 0;
        for (int i = j; i >= 0; i--) {
            s+=B[i];
            if (s < K) {
                int arr2len = smallestKsumSubarray(j+1, N, K-s);
                if (arr2len >= 0)
                    ans = min(ans, j - i + 1 + arr2len);
            } else if(s == K) {
                ans = min(ans, j-i+1);
            }
        }
    }
    
    
    if (ans > N)
        ans = -1;
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
