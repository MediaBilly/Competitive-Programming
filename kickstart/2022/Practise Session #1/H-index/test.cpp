#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_multiset<int> mlset;
    mlset.insert(21);
    mlset.insert(13);
    mlset.insert(7);
    mlset.insert(7);
    mlset.insert(4);
    // mlset.erase(7);
    for (auto it = mlset.begin();it != mlset.end();) {
        cout << *it << endl;
        it = mlset.erase(it);
    }
    cout << "-----\n";
    for (auto a: mlset) {
        cout << a << endl;
    }
    cout << "---\n";
    return 0;
}
