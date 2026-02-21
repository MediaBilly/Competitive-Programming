#include <iostream>
#include <string>

using namespace std;

int main(int argc,char *args[]) {
    string dir;
    int hor=0,depth=0, aim=0, amount;
    while (cin >> dir >> amount) {
        if (dir == "forward") {
            hor+=amount;
            depth+=aim*amount;
        }
        else if (dir == "down")
            aim+=amount;
        else if (dir == "up")
            aim-=amount;
    }
    cout << hor * depth << endl;

    return 0;
}