#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << 1 << endl << atoi(argv[1]) << endl;
    for (int i = 0; i < atoi(argv[1]); i++) {
        cout << rand() % 1000000001 << ' ';
    }
    cout << endl;
    for (int i = 1; i <= atoi(argv[1]); i++) {
        cout << rand() % i << ' ';
    }
    cout << endl;
    return 0;
}
