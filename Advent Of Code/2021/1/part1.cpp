#include <iostream>

using namespace std;

int main(int argc,char *args[]) {
    int num,cnt=0, prev=-1,ans=0;
    while (cin >> num) {
        if (cnt++>0&&num>prev) {
            ans++;
        }
        prev=num;
    }
    cout << ans;
    return 0;
}