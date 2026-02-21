#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

char reverseMap(vector<char>& wireMap, char c) {
    for (size_t i = 0; i < wireMap.size(); i++) {
        if (c == wireMap[i]) {
            return 'a'+i;
        }
    }
    return 'a';
}

int main(int argc,char *args[]) {
    string line;
    unordered_map<int, unordered_set<char>> dec2bcd;
    dec2bcd[0] = {'a', 'b', 'c', 'e', 'f', 'g'};
    dec2bcd[1] = {'c','f'};
    dec2bcd[2] = {'a','c','d','e','g'};
    dec2bcd[3] = {'a','c','d','f','g'};
    dec2bcd[4] = {'b','c','d','f'};
    dec2bcd[5] = {'a','b','d','f','g'};
    dec2bcd[6] = {'a','b','d','e','f','g'};
    dec2bcd[7] = {'a','c','f'};
    dec2bcd[8] = {'a','b','c','d','e','f','g'};
    dec2bcd[9] = {'a','b','c','d','f','g'};
    uint64_t ans = 0;
    while (getline(cin, line)) {
        string patterns, nums;
        stringstream ss(line);
        getline(ss, patterns, '|');
        getline(ss, nums, '|');
        // cout << patterns << ' ' << nums << endl;
        stringstream patternsStream(patterns);
        string pattern;
        vector<string> patternsVec;
        while (patternsStream >> pattern) {
            patternsVec.push_back(pattern);
        }
        vector<char> wireMap = {'a','b','c','d','e','f','g'};
        bool ok = false;
        do {
            // cout << "Perm:" << perm << endl;
            ok = true;
            for (string pat: patternsVec) {
                unordered_set<char> tmpSet;
                for (char c: pat) {
                    tmpSet.insert(reverseMap(wireMap, c));
                }
                ok = false;
                for (int digit = 0;!ok && digit <= 9; digit++) {
                    if (dec2bcd[digit] == tmpSet) {
                        ok = true;
                    }
                }
                if (!ok) {
                    break;
                }
            }
        } while(!ok && next_permutation(wireMap.begin(), wireMap.end()));
        stringstream numsStream(nums);
        string numS;
        // patternMap.clear();
        int num = 0, powten=1000;
        while (numsStream >> numS) {
            unordered_set<char> tmpSet;
            for (char c: numS) {
                tmpSet.insert(reverseMap(wireMap, c));
            }
            for (int digit=0;digit<=9;digit++) {
                if (dec2bcd[digit]==tmpSet) {
                    num += digit * powten;
                    powten/=10;
                    break;
                }
            }
        }
        // cout << num << endl;
        ans+=num;
    }
    cout << ans << endl;
}