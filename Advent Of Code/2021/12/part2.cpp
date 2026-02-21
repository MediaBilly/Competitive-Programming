#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, unordered_set<string>> adj;
unordered_map<string, int> visitTimes;

int paths = 0;

bool small_visited_twice = false;

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
    if (string_is_uppercase(u)) {
        for (auto v : adj[u]) {
            dfs(v);
        }
    } else if (!string_is_uppercase(u) && (u != "start" && visitTimes[u] < 2 || u == "start" && visitTimes[u] < 1)) {
        if (small_visited_twice && visitTimes[u] < 1 || !small_visited_twice && visitTimes[u] < 2) {
            visitTimes[u]++;
            if (visitTimes[u]==2) {
                small_visited_twice = true;
            }
            for (auto v : adj[u]) {
                dfs(v);
            }
            if (visitTimes[u]==2) {
                small_visited_twice = false;
            }
            visitTimes[u]--;
        }
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
        visitTimes[u] = 0;
        visitTimes[v] = 0;
    }
    dfs("start");

    cout << paths << endl;
    return 0;
}