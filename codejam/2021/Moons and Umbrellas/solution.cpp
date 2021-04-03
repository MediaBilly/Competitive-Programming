#include <bits/stdc++.h>

using namespace std;

bool inQueue[1000];

void solve(int x) {
    int X,Y;
    string S;
    cin >> X >> Y;
    cin >> S;
    int ans = 0;
    queue<int> checkpoints;
    memset(inQueue,false,sizeof(inQueue));
    for (int i = 0; i < S.length()-1; i++) {
        if (S[i]=='C'&&S[i+1]=='J') {
            ans += X;
        } else if (S[i]=='J'&&S[i+1]=='C') {
            ans += Y;
        } 
        if (S[i]!='?') {
            if (i > 0 && S[i-1]=='?' && !inQueue[i-1]) {
                inQueue[i-1]=true;
                checkpoints.push(i-1);
            }
            if (i < S.length()-1 && S[i+1]=='?' && !inQueue[i+1]) {
                inQueue[i+1]=true;
                checkpoints.push(i+1);
            }
        }
    }
    while (checkpoints.size() > 0) {
        int i = checkpoints.front();

        int tmp=0,finalS=INT_MAX;
        char finalLet;
        // C
        if (i > 0) { // ...J(C)...
            if (S[i-1]=='J') {
                tmp += Y;
            } else if (S[i-1]=='?'&&!inQueue[i-1]) {
                inQueue[i-1]=true;
                checkpoints.push(i-1);
            }
        }
        if (i < S.length()-1) { // ...(C)J...
            if (S[i+1]=='J') {
                tmp += X;
            } else if (S[i+1]=='?'&&!inQueue[i+1]) {
                inQueue[i+1]=true;
                checkpoints.push(i+1);
            }
        }
        if (ans + tmp < finalS) {
            finalS = ans + tmp;
            finalLet='C';
        }
        //cout << tmp << " ";
        
        // J
        tmp = 0;
        if (i > 0) { // ...C(J)...
            if (S[i-1]=='C') {
                tmp += X;
            } 
        }
        if (i < S.length()-1) { // ...(J)C...
            if (S[i+1]=='C') {
                tmp += Y;
            } 
        }
        if (ans + tmp < finalS) {
            finalS = ans + tmp;
            finalLet='J';
        }

        S[i]=finalLet;
        ans=finalS;

        inQueue[i]=false;
        checkpoints.pop();
    }
    
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
