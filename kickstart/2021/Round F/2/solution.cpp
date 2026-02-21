#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int s;
    int e;
    int h;
} attr;

bool cmp( attr *a1, attr *a2) {
    return a1->h > a2->h;
}

void solve(int x) {
    unordered_map<int,vector<attr*>> attrsPerDay;
    int D,N,K,hi,si,ei;
    cin >> D >> N >> K;
    attr *a;
    vector<attr*> attrs;
    for (int i=0;i<N;i++) {
        cin >> hi >> si >> ei;
        a = new attr({ si, ei, hi });
        attrs.push_back(a);
        for (int d=si;d<=ei;d++) {
            attrsPerDay[d].push_back(a);
        }
    }
    for (auto& d: attrsPerDay) {
        sort(d.second.begin(), d.second.end(), cmp);
    }
    int ans = -1;
    for (auto d: attrsPerDay) {
        int tmp = 0;
        for (int i=0;i<min(K,(int)d.second.size());i++) {
            tmp+=d.second[i]->h;
        }
        ans = max(ans, tmp);
    }
    cout << "Case #" << x << ": " << ans << endl;
    for (auto a: attrs) {
        delete a;
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
