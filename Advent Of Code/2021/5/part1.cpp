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