#include <iostream>
#include <stack>

using namespace std;

uint64_t illegal_score(string line) {
    stack<char> s;
    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<') {
            s.push(line[i]);
        } else if (line[i] == ')' && s.top() != '(') {
            return 3;
        } else if (line[i] == ']' && s.top() != '[') {
            return 57;
        } else if (line[i] == '}' && s.top() != '{') {
            return 1197;
        } else if (line[i] == '>' && s.top() != '<') {
            return 25137;
        } else {
            s.pop();
        }
    }
    return 0;
}

int main(int argc,char *args[]) {
    string line;
    uint64_t ans = 0;
    while (cin >> line) {
        ans+=illegal_score(line);
    }
    cout << ans << endl;
    
    return 0;
}