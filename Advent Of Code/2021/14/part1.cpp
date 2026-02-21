#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>

using namespace std;

char pat[3];

int main() {
    string tmpl;
    cin >> tmpl;

    char ins;
    unordered_map<string, char> between;
    while (scanf("%s -> %c", pat, &ins) != EOF) {
        between[string(pat)] = ins;
    }

    for (int step=1;step<=10;step++) {
        for (size_t i = 1; i < tmpl.length(); i++) {
            string p = tmpl.substr(i-1, 2);
            if (between.find(p) != between.end()) {
                tmpl.insert(i, 1, between[p]);
                i++;
            }
        }
    }
    unordered_map<char, uint64_t> cnt;
    for (char c: tmpl) {
        if (cnt.find(c) == cnt.end()) {
            cnt[c] = 1;
        } else {
            cnt[c]++;
        }
    }

    uint64_t maxcnt=0, mincnt = UINT64_MAX;
    for (auto a: cnt) {
        maxcnt = max(maxcnt, a.second);
        mincnt = min(mincnt, a.second);
    }
    cout << maxcnt - mincnt << endl;
    
    return 0;
}