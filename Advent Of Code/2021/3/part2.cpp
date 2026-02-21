#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc,char *args[]) {
    int len;
    unordered_set<string> bitstringso2, bitstringsco2;
    string bitstring;
    cin >> bitstring;
    len = bitstring.length();
    do {
        bitstringso2.insert(bitstring);
        bitstringsco2.insert(bitstring);
    } while(cin >> bitstring);

    for (int i = 0; i < len && bitstringso2.size()>1; i++) {
        unordered_set<string> zeros;
        unordered_set<string> ones;
        for (auto s: bitstringso2) {
            if (s[i]=='0')
                zeros.insert(s);
            else  
                ones.insert(s);
        }
        
        if (ones.size()>=zeros.size()) {
            for (auto st: zeros) {
                bitstringso2.erase(st);
            }
        } else {
            for (auto st: ones) {
                bitstringso2.erase(st);
            }
        }
    }

    for (int i = 0; i < len && bitstringsco2.size()>1; i++) {
        unordered_set<string> zeros;
        unordered_set<string> ones;
        for (auto s: bitstringsco2) {
            if (s[i]=='0')
                zeros.insert(s);
            else  
                ones.insert(s);
        }
        
        if (zeros.size()<=ones.size()) {
            for (auto st: ones) {
                bitstringsco2.erase(st);
            }
        } else {
            for (auto st: zeros) {
                bitstringsco2.erase(st);
            }
        }
    }

    for (auto a: bitstringso2) {
        cout << a << endl;
    }
    cout << endl;

    for (auto a: bitstringsco2) {
        cout << a << endl;
    }
    cout << endl;
    
    return 0;
}