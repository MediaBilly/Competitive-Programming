#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc,char *args[]) {
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        string patterns, nums;
        stringstream ss(line);
        getline(ss, patterns, '|');
        getline(ss, nums, '|');
        // cout << patterns << ' ' << nums << endl;
        stringstream patternsStream(patterns);
        string pattern;
        while (patternsStream >> pattern);
        stringstream numsStream(nums);
        string numS;
        while (numsStream >> numS) {
            //  1                   7                   4                   8
            if (numS.length()==2 || numS.length()==3 || numS.length()==4 || numS.length()==7) {
                // cout << numS.length() << ' ' << numS << endl;
                ans++;
            }
        }
        // cout << endl;
    }
    cout << ans << endl;
}