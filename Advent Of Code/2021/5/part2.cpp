#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[1000][1000];

int main(int argc,char *args[]) {
    int x1, y1, x2, y2;
    memset(arr, 0, sizeof(arr));
    int ans = 0;
    while (scanf("%d,%d -> %d,%d",&x1, &y1, &x2, &y2) != EOF) {
        if (x1 == x2) {
            for (int i = min(y1, y2); i <= max(y1, y2); i++) {
                arr[i][x1]++;
            }
        } else if (y1 == y2) {
            for (int i = min(x1, x2); i <= max(x1, x2); i++) {
                arr[y1][i]++;
            }
        } else if (abs(y2-y1)/abs(x2-x1) == 1) {
            int xs, ys, xe;
            if (x1 < x2) {
                xs = x1;
                xe = x2;
                ys = y1;
            } else {
                xs = x2;
                xe = x1;
                ys = y2;
            }
            int slope = (y2-y1)/(x2-x1);
            for (int i = 0; i <= xe-xs; i++) {
                arr[ys+i*slope][xs+i]++;
            }
        } 
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            ans+=arr[i][j]>1;
        }
    }
    cout << ans << endl;
    
     
    return 0;
}