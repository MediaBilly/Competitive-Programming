#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> Rsorted;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

int binsearch(int val, int lo, int hi) {
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (lo == hi) {
            return mid;
        }
        if (Rsorted[mid].second <= val) {
            if (mid < hi && Rsorted[mid+1].second > val || mid == hi) {
                return mid;
            } else {
                lo = mid+1;
            }
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

void solve(int x) {
    int N, Ri;
    cin >> N;
    vector<int> R;
    Rsorted.clear();
    for (int i=0;i<N;i++) {
        cin >> Ri;
        R.push_back(Ri);
        Rsorted.push_back(make_pair(i, Ri));
    }
    sort(Rsorted.begin(), Rsorted.end(), sortbysec);
    // for (int i=0;i<N;i++) {
    //     cout << Rsorted[i].first << ',' << Rsorted[i].second << ' ';
    // }
    // cout << endl;
    cout << "Case #" << x << ": ";
    for (int i=0;i<N;i++) {
        int j = binsearch(2 * R[i], 0, N-1);
        if (j == -1) {
            cout << -1;
        } else {
            if (Rsorted[j].first != i) {
                cout << Rsorted[j].second;
            } else {
                if (j > 0) {
                    cout << Rsorted[j-1].second;
                } else {
                    cout << -1;
                }
            }
            // cout << j << ':' << Rsorted[j].first << ',' << Rsorted[j].second;
        }
        cout << ' ';
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
