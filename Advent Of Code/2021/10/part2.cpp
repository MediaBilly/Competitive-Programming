#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

uint64_t autocomplete_score(string line) {
    stack<char> s;
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<') {
            s.push(line[i]);
        } else if (line[i] == ')' && s.top() != '(') {
            return 0;
        } else if (line[i] == ']' && s.top() != '[') {
            return 0;
        } else if (line[i] == '}' && s.top() != '{') {
            return 0;
        } else if (line[i] == '>' && s.top() != '<') {
            return 0;
        } else {
            s.pop();
        }
    }
    uint64_t score = 0;
    while(s.size() > 0) {
        switch(s.top()) {
            case '(':
                score = 5 * score + 1;
                break;
            case '[':
                score = 5 * score + 2;
                break;
            case '{':
                score = 5 * score + 3;
                break;
            case '<':
                score = 5 * score + 4;
                break;
            default:
                break;
        }
        s.pop();
    }
    return score;
}

int main(int argc,char *args[]) {
    string line;
    vector<uint64_t> scores;
    while (cin >> line) {
        uint64_t score = autocomplete_score(line);
        if (score != 0) {
            scores.push_back(score);
        }
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size()/2] << endl;
    
    return 0;
}