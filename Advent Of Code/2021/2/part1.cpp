#include <iostream>
#include <string>

using namespace std;

int main(int argc,char *args[]) {
    string dir;
    int hor=0,depth=0, amount;
    while (cin >> dir >> amount) {
        if (dir == "forward")
            hor+=amount;
        else if (dir == "down")
            depth+=amount;
        else if (dir == "up")
            depth-=amount;
    }
    cout << hor * depth << endl;

    return 0;
}