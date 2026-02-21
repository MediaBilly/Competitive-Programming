#include <iostream>
#include <string>
#include <vector>

#define TOTAL_DAYS 256

using namespace std;

int main(int argc,char *args[]) {
    string numS;
    vector<uint64_t> state;
    state.resize(9, 0);
    while (getline(cin, numS, ',')) {
        state[atoi(numS.c_str())]++;
    }

    for (int day = 1; day <= TOTAL_DAYS; day++) {
        uint64_t new6 = state[0]+state[7];
        uint64_t old0 = state[0];
        // shift
        for (int i = 1; i < state.size(); i++) {
            state[i-1]=state[i];
        }
        state[8]=old0;
        state[6]=new6;
        
    }
    uint64_t ans = 0;
    for (auto a: state){
        ans+=a;
    }
    
    cout << ans << endl;
    
    return 0;
}