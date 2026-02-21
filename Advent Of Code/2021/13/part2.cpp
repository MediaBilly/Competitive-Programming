#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define MAXX 1307
#define MAXY 893

bool grid[MAXY+1][MAXX+1];

int maxx=-1, maxy = -1;

void foldY(int foldPoint) {
    for (int y = foldPoint+1, ypr = foldPoint-1;y <= maxy;y++) {
        for (int x = 0;x <= maxx;x++) {
            if (grid[y][x])
                grid[ypr][x] = true;
        }
        ypr--;
    }
    maxy = foldPoint-1;
}

void foldX(int foldPoint) {
    for (int y = 0;y <= maxy;y++) {
        for (int x = foldPoint+1, xpr = foldPoint-1;x <= maxx;x++) {
            if (grid[y][x])
                grid[y][xpr] = true;
            xpr--;
        }
    }
    maxx = foldPoint-1;
}

void print() {
    for (int y = 0;y <= maxy;y++) {
        for (int x = 0;x <= maxx;x++) {
            cout << (grid[y][x] ? '#' : '.');
        }
        cout << endl;
    }
}

int main() {
    int x,y;
    memset(grid, false, sizeof(grid));
    while (scanf("%d,%d",&x,&y)) {
        grid[y][x] = true;
        maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    string instr;
    while (cin >> instr >> instr >> instr) {
        char dir = instr[0];
        int foldPoint = atoi(instr.substr(2, instr.length()-2).c_str());

        switch(dir) {
            case 'y':
                foldY(foldPoint);
                break;
            case 'x':
                foldX(foldPoint);
                break;
            default:
                break;
        }
    }
    print();
    
    return 0;
}