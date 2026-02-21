#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, unordered_set<string>> adj;
unordered_set<string> visited;

int paths = 0;

bool string_is_uppercase(string s) {
    for (char c: s) {
        if (islower(c)) {
            return false;
        }
    }
    return true;
}

void dfs(string u) {
    if (u == "end") {
        paths++;
        return;
    }
    if (visited.find(u) == visited.end() || string_is_uppercase(u)) {
        visited.insert(u);
        for (auto v : adj[u]) {
            dfs(v);
        }
        visited.erase(u);
    }
}

int main() {
    string str;
    while (getline(cin, str)) {
        string u, v;
        stringstream ss(str);
        getline(ss, u, '-');
        getline(ss, v, '-');
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs("start");

    cout << paths << endl;
    return 0;
}