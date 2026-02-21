#include <bits/stdc++.h>

using namespace std;

unordered_set<int> s1, s2;
long long sum1 = 0, sum2 = 0;

void addnum(int num) {
    if (sum1 < sum2) {
        s1.insert(num);
        sum1 += num;
    } else {
        s2.insert(num);
        sum2 += num;
    }
}

void solve() {
    int N;
    cin >> N;
    s1.clear();
    s2.clear();
    sum1 = sum2 = 0;
    for (int i = 1; i <= 70; i++) {
        cout << 2 * i + 1 << ' ';
        addnum(2 * i + 1);
    }
    int p2 = 1;
    for (int i=0;i<30;i++) {
        cout << p2 << ' ';
        p2 <<= 1;
    }
    cout << endl;
    for (int i=0;i<100;i++){
        int num;
        cin >> num;
        addnum(num);
    }
    p2 = 1 << 29;
    while (p2 > 0) {
        addnum(p2);
        p2 >>= 1;
    }
    for (int i: s1) {
        cout << i << ' ';
    }
    cout << endl;
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
