#include <iostream>
#include <string>
#include <vector>

#define TOTAL_DAYS 80

using namespace std;

int main(int argc,char *args[]) {
    string numS;
    vector<uint8_t> state;
    while (getline(cin, numS, ',')) {
        state.push_back(atoi(numS.c_str()));
    }

    for (int day = 1; day <= TOTAL_DAYS; day++) {
        // cout << day << '\n';
        size_t sz = state.size();
        for (size_t i = 0; i < sz; i++) {
            if (state[i]==0) {
                state[i]=6;
                state.push_back(8);
            } else {
                state[i]--;
            }
        }
    }
    cout << state.size() << endl;
    
    return 0;
}