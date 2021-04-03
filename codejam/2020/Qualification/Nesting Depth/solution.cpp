#include <bits/stdc++.h>

using namespace std;

void solve(int x) {
    string str1,str2;
    cin >> str1;
    int nd = 0,dnd,d;
    for (int i = 0; i < str1.length(); i++) {
        d = str1[i]-'0';
        if (d > nd) {
            dnd = d - nd;
            nd += dnd;
            for (int j = 0; j < dnd; j++) {
                str2 += '(';
            }            
        } else if (d < nd) {
            dnd = nd - d;
            nd -= dnd;
            for (int j = 0; j < dnd; j++) {
                str2 += ')';
            } 
        }
        str2 += str1[i];
    }
    while (nd--) {
        str2 += ')';
    }
    
    cout << "Case #" << x << ": " << str2 << endl;
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
