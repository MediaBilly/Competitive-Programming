#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc,char *args[]) {
    vector<int> count0, count1;
    string bitstring;
    cin >> bitstring;
    count0.resize(bitstring.length(),0);
    count1.resize(bitstring.length(),0);
    do {
        for (int i = 0; i < bitstring.length(); i++) {
            if (bitstring[i]=='0')
                count0[i]++;
            else
                count1[i]++;
        }
        
    } while(cin >> bitstring);
    int gammaRate=0, epsilonRate=0, bitmask = 1 << bitstring.length()-1;
    for (int i = 0; i < bitstring.length(); i++) {
        if (count1[i] > count0[i])
            gammaRate |= bitmask;
        if (count1[i] < count0[i])
            epsilonRate |= bitmask;
        bitmask >>= 1;
    }
    cout << gammaRate * epsilonRate << endl;
    
    return 0;
}