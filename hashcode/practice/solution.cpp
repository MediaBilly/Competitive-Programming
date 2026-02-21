#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int index;
    set<string> ingredients;
} Pizza;

typedef struct {
    int size;
    int pizzas[4];
    bool ok;
} Team;

vector<Pizza> pizzas;

unsigned int score(Team &t) {
    set<string> ingr;
    for (int p = 0;p < t.size;p++) {
        if (t.pizzas[p] == -1) {
            return 0;
        }
        for (auto i : pizzas[t.pizzas[p]].ingredients) {
           ingr.insert(i);
        }
    }
    return ingr.size();
}

int main(int argc,char *args[]) {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    int M,T2,T3,T4;

    cin >> M >> T2 >> T3 >> T4;
    
    int I;
    string ingredient;
    for (int i = 0; i < M; i++) {
        cin >> I;
        set<string> curPizza;
        for (int j = 0; j < I; j++) {
            cin >> ingredient;
            curPizza.insert(ingredient);
        }
        pizzas.push_back({i,curPizza});
    }

    // Form teams
    vector<Team> teams;
    int p = 0;
    Team t;
    for (int i = 0; i < T2; i++) {
        t.size = 2;
        t.pizzas[0] = (p < M ? p++ : -1);
        t.pizzas[1] = (p < M ? p++ : -1);
        t.ok = true;
        teams.push_back(t);
    }
    for (int i = 0; i < T3; i++) {
        t.size = 3;
        t.pizzas[0] = (p < M ? p++ : -1);
        t.pizzas[1] = (p < M ? p++ : -1);
        t.pizzas[2] = (p < M ? p++ : -1);
        t.ok = true;
        teams.push_back(t);
    }
    for (int i = 0; i < T4; i++) {
        t.size = 4;
        t.pizzas[0] = (p < M ? p++ : -1);
        t.pizzas[1] = (p < M ? p++ : -1);
        t.pizzas[2] = (p < M ? p++ : -1);
        t.pizzas[3] = (p < M ? p++ : -1);
        t.ok = true;
        teams.push_back(t);
    }

    // TODO: Maximization
    
    // Calculate teams which were given pizza
    unsigned int tmpScore;
    unsigned long long totalScore = 0;
    int D = 0;
    for (unsigned int i = 0;i < teams.size();i++) {
        tmpScore = score(teams[i]);
        if (tmpScore > 0) {
            totalScore += tmpScore * tmpScore;
            D++;
        } else {
            teams[i].ok = false;
        }
    }

    // Output
    cout << D << endl;
    for (unsigned int i = 0;i < teams.size();i++) {
        if (teams[i].ok) {
            cout << teams[i].size << " ";
            for (int j = 0;j < teams[i].size;j++) {
                cout << teams[i].pizzas[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}