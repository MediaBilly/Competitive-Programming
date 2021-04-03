#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    int count;
    unordered_map<char,TrieNode*> children;
    TrieNode() {
        this->count = 1;
    }
    ~TrieNode() {
        for (auto c : children) {
            delete c.second;
        }
    }
};

class Trie
{
private:
    TrieNode *root;
    int count(TrieNode *node,int K) {
        int cnt = node->count/K;
        for (auto n : node->children) {
            cnt += count(n.second,K);
        }
        return cnt;
    }
public:
    Trie() {
        this->root = new TrieNode();
    }
    void insert(string prefix) {
        TrieNode *node = this->root;
        for (int i = 0;i < prefix.length();i++) {
            if (node->children.find(prefix[i]) != node->children.end()) {
                node = node->children[prefix[i]];
                node->count++;
            } else {
                node->children[prefix[i]] = new TrieNode();
                node = node->children[prefix[i]];
            }
        }
    }
    int getCount(int K) {
        return this->count(this->root,K);
    }
    ~Trie() {
        delete this->root;
    }
};


void solve(int x) {
    int N,K;
    string str;
    unordered_map<string,int> cnt;
    Trie trie;
    cin >> N >> K;
    for (int i =0;i<N;i++) {
        cin >> str;
        trie.insert(str);
    }
    cout << "Case #" << x << ": " << trie.getCount(K) << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
