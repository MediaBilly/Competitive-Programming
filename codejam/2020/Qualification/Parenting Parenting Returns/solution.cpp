#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int idx;
    int s;
    int e;
    char parent;
} Activity;

bool cmpStart(Activity act1, Activity act2) {
    return act1.s < act2.s;
}

bool cmpIdx(Activity act1, Activity act2) {
    return act1.idx < act2.idx;
}

void solve(int x) {
    int N;
    cin >> N;
    vector<Activity> activities;
    Activity act;
    for (int i = 0; i < N; i++) {
        cin >> act.s >> act.e;
        act.idx=i;
        activities.push_back(act);
    }
    sort(activities.begin(),activities.end(),cmpStart);
    Activity act1,act2;
    char curParent;
    string ans;
    act1.s=act1.e=act2.s=act2.e=-1;
    for (int i = 0; i < N; i++) {
        if (activities[i].s >= act1.e) {
            curParent = 'C';
            act1 = activities[i];
        } else if (activities[i].s >= act2.e) {
            curParent = 'J';
            act2 = activities[i];
        } else {
            cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
            return;
        }
        activities[i].parent=curParent;
    }
    sort(activities.begin(),activities.end(),cmpIdx);
    cout << "Case #" << x << ": ";
    for (int i = 0; i < N; i++) {
        cout << activities[i].parent;
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
