#include <bits/stdc++.h>

using namespace std;

string P[50];
int ptr1[50],ptr2[50];
bool done[50];

void solve() {
    int N;
    cin >> N;
    int fc=0,lc=0;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        if (P[i][0]!='*') {
            fc=i;
        }
        if (P[i][P[i].length()-1]!='*') {
            lc=i;
        }
        ptr2[i]=P[i].length()-1;
    }
    memset(ptr1,0,sizeof(ptr1));
    string pref="",suf="",mid="";
    char curCh = P[fc][ptr1[fc]];
    int remPs = N;
    memset(done,false,sizeof(done));
    while (remPs) {
        char nextCh;
        for (int i = 0; i < N; i++) {
            if (!done[i]) {
                if (P[i][ptr1[i]]!='*') {
                    if (P[i][ptr1[i]]==curCh) {
                        ptr1[i]++;
                        if (P[i][ptr1[i]]!='*') {
                            nextCh=P[i][ptr1[i]];
                        }
                    } else {
                        cout << "*" << endl;
                        return;
                    }
                } else {
                    remPs--;
                    done[i]=true;
                }
            }
        }
        if (curCh!='*'&&remPs>0) {
            pref+=curCh;
        }
        curCh = nextCh;
    }
    curCh = P[lc][ptr2[lc]];
    remPs = N;
    memset(done,false,sizeof(done));
    while (remPs) {
        char nextCh;
        for (int i = 0; i < N; i++) {
            if (!done[i]) {
                if (P[i][ptr2[i]]!='*') {
                    if (P[i][ptr2[i]]==curCh) {
                        ptr2[i]--;
                        if (P[i][ptr2[i]]!='*') {
                            nextCh=P[i][ptr2[i]];
                        }
                    } else {
                        cout << "*" << endl;
                        return;
                    }
                } else {
                    remPs--;
                    done[i]=true;
                }
            }
        }
        if (curCh!='*'&&remPs>0) {
            suf=curCh+suf;
        }
        curCh = nextCh;
    }
    for (int i = 0; i < N; i++) {
        ptr1[i]++;
        ptr2[i]--;
    }
    for (int i = 0; i < N; i++) {
        while (ptr1[i] <= ptr2[i]) {
            if (P[i][ptr1[i]]!='*') {
                mid+=P[i][ptr1[i]];
            }
            ptr1[i]++;
        }
    }
    
    cout << pref + mid + suf << endl;
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
