#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    int N,X,Y;
    cin >> N >> X >> Y;
    int sum;
    bool possible = false;
    for (sum = 1;sum < N * (N+1)/2;sum++) {
        if ((double)sum/((double)N * (N+1)/2 - sum) == ((double)X/(double)Y)) {
            possible = true;
            break;
        }
    }
    cout << "Case #" << x << ": ";
    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> nums;
    for (int i=0;i<=N;i++) {
        nums.push_back(i);
    }
    vector<int> res;
    while (nums.size() > 0 && sum >= nums[N]) {
        // cout << nums[N] << ' ' << sum << endl;
        res.push_back(N);
        nums.pop_back();
        sum -= N;
        N--;
    }
    if (sum > 0) {
        res.push_back(nums[sum]);
    }
    cout << "POSSIBLE" << endl;
    cout << res.size() << endl;
    for (int n: res) {
        cout << n << ' ';
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
