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

    unordered_map<string, uint64_t> patcnt;
    unordered_map<char, uint64_t> letcnt;
    letcnt[tmpl[0]]=1;
    for (size_t i=1;i < tmpl.length();i++) {
        string p = tmpl.substr(i-1, 2);
        if (patcnt.find(p) != patcnt.end()) {
            patcnt[p]++;
        } else {
            patcnt[p] = 1;
        }

        if (letcnt.find(tmpl[i]) != letcnt.end()) {
            letcnt[tmpl[i]]++;
        } else {
            letcnt[tmpl[i]]=1;
        }
    }

    for (int step=1;step<=40;step++) {
        unordered_map<string, uint64_t> patcnt_tmp = patcnt;
        unordered_map<char, uint64_t> letcnt_tmp = letcnt;
        for (auto a: patcnt) {
            if (a.second > 0) {
                if (between.find(a.first) != between.end()) {
                    char btwn = between[a.first];
                    if (letcnt_tmp.find(btwn) != letcnt_tmp.end()) {
                        letcnt_tmp[btwn] += a.second;
                    } else {
                        letcnt_tmp[btwn] = a.second;
                    }
                    patcnt_tmp[a.first] -= a.second;

                    string pat1 = "";
                    pat1 += a.first[0];
                    pat1 += btwn;
                    if (patcnt_tmp.find(pat1) != patcnt_tmp.end()) {
                        patcnt_tmp[pat1]+=a.second;
                    } else {
                        patcnt_tmp[pat1]=a.second;
                    }

                    string pat2 = "";
                    pat2 += btwn;
                    pat2 += a.first[1];
                    if (patcnt_tmp.find(pat2) != patcnt_tmp.end()) {
                        patcnt_tmp[pat2]+=a.second;
                    } else {
                        patcnt_tmp[pat2]=a.second;
                    }
                }
            }
        }
        patcnt = patcnt_tmp;
        letcnt = letcnt_tmp;
    }

    uint64_t maxcnt=0, mincnt = UINT64_MAX;
    for (auto a: letcnt) {
        maxcnt = max(maxcnt, a.second);
        mincnt = min(mincnt, a.second);
    }
    cout << maxcnt - mincnt << endl;
    
    return 0;
}