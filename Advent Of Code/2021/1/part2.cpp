#include <iostream>

using namespace std;

int main(int argc,char *args[]) {
    int A,B,C,cnt=0,ans=0, prevSum=-1;
    cin >> A >> B;
    while (cin >> C) {
        if (cnt++>0&&A+B+C>prevSum) {
            ans++;
        }
        prevSum=A+B+C;
        A=B;
        B=C;
    }
    cout << ans;
    return 0;
}