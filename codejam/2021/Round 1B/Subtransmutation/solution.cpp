#include <bits/stdc++.h>

using namespace std;

void insertKTimes(multiset<int> &mset, int k, int val) {
    for (int i = 0; i < k; i++) {
        mset.insert(val);
    }
}

void deleteOnce(multiset<int> &mset, int val) {
    auto itr = mset.find(val);
    if (itr != mset.end()) {
        mset.erase(itr);
    }
}

void solve() {
    int N,A,B,Ui;
    cin >> N >> A >> B;
    multiset<int> Start, Goal;
    for (int i = 1; i <= N; i++) {
        cin >> Ui;
        insertKTimes(Goal, Ui, i);
    }

    for (int i = 1; i <= 402; i++) {
        multiset<int> S = Start, G = Goal;
        S.insert(i);

        while (!S.empty()) {
            vector<int> intr(S.size() + G.size());
            set_intersection(S.begin(), S.end(), G.begin(), G.end(), intr.begin());
            for (auto a : intr) {
                deleteOnce(S, a);
                deleteOnce(G, a);
            }

            if (G.empty()) {
                cout << i << endl;
                return;
            }

            int maxM = 0;
            for (auto m : S) {
                maxM = max(maxM, m);
            }
            int cnt = S.count(maxM);

            S.erase(maxM);
            if (maxM - A > 0) {
                insertKTimes(S, cnt, maxM - A);
            }
            if (maxM - B > 0) {
                insertKTimes(S, cnt, maxM - B);
            }
        }
        
    }
    cout << "IMPOSSIBLE\n";
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}
