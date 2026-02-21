#include <iostream>
#include <cstring>

using namespace std;

int lvl[10][10];
bool flashed[10][10];

int flashes = 0;

void flash(int i, int j) {
    if (i > 0) {
        if (j > 0) {
            lvl[i-1][j-1]++;
        }
        lvl[i-1][j]++;
        if (j < 9) {
            lvl[i-1][j+1]++;
        }
    }
    if (j > 0) {
        lvl[i][j-1]++;
    }
    if (j < 9) {
        lvl[i][j+1]++;
    }
    if (i < 9) {
        if (j > 0) {
            lvl[i+1][j-1]++;
        }
        lvl[i+1][j]++;
        if (j < 9) {
            lvl[i+1][j+1]++;
        }
    }
}

int main(int argc,char *args[]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0;j < 10;j++) {
            char c;
            cin >> c;
            lvl[i][j] = (int)(c - '0');
        }
    }

    for (int step = 0;step < 100;step++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0;j < 10;j++) {
                lvl[i][j]++;
            }
        }
        int newFlashes = 0;
        memset(flashed, false, sizeof(flashed));
        do {
            newFlashes = 0;
            for (int i = 0; i < 10; i++) {
                for (int j = 0;j < 10;j++) {
                    if (lvl[i][j]>9 && !flashed[i][j]) {
                        flash(i, j);
                        flashed[i][j] = true;
                        newFlashes++;
                    }
                }
            }
            flashes+=newFlashes;
        } while(newFlashes > 0);
        for (int i = 0; i < 10; i++) {
            for (int j = 0;j < 10;j++) {
                if (flashed[i][j]) {
                    lvl[i][j] = 0;
                }
            }
        }
    }
    cout << flashes << endl;
    
    return 0;
}