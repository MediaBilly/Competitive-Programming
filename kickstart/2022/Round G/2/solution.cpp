#include <bits/stdc++.h>

using namespace std;

int Rh, Rs;

struct stone {
    int x;
    int y;

    stone(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double dist() {
        return sqrt((this->x) * (this->x) + (this->y) * (this->y));
    }

    bool inHouse() {
        return dist() <= Rh + Rs;
    }
};

void solve(int x) {
    vector<stone> redTeam;
    vector<stone> yellowTeam;
    cin >> Rh >> Rs;
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        int x, y;
        cin >> x >> y;
        stone st(x, y);
        redTeam.push_back(st);
    }
    int M;
    cin >> M;
    for (int i=0;i<M;i++) {
        int x, y;
        cin >> x >> y;
        stone st(x, y);
        yellowTeam.push_back(st);
    }
    int ansR = 0, ansY = 0;
    for (int i = 0; i < redTeam.size(); i++) {
        int score = 0;
        if (redTeam[i].inHouse()) {
            score = 1;
            for (int j = 0; j < yellowTeam.size(); j++) {
                if (yellowTeam[j].dist() < redTeam[i].dist()) {
                    score = 0;
                }
            }
            
        }
        ansR += score;
    }

    for (int i = 0; i < yellowTeam.size(); i++) {
        int score = 0;
        if (yellowTeam[i].inHouse()) {
            score = 1;
            for (int j = 0; j < redTeam.size(); j++) {
                if (redTeam[j].dist() < yellowTeam[i].dist()) {
                    score = 0;
                }
            }
            
        }
        ansY += score;
    }
    
    cout << "Case #" << x << ": " << ansR << " " << ansY << endl;
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
