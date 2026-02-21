#include <bits/stdc++.h>

using namespace std;

unordered_set<unsigned int> given;

typedef struct {
    unsigned int index;
    set<string> ingredients;
} Pizza;

bool pizzacmp(Pizza p1, Pizza p2) {
    return p1.ingredients.size() > p2.ingredients.size();
}

set<string> ingr_union(set<string> &s1,set<string> &s2) {
    set<string> ret;
    for (auto a : s1) {
        ret.insert(a);
    }
    for (auto a : s2) {
        ret.insert(a);
    }
    return ret;
}

set<string> find_best_union(vector<Pizza> &pizzas,set<string> &s, unsigned int *new_idx) {
    set<string> ret,tmp;
    unsigned int best = 0;
    *new_idx = 0;
    for (unsigned int i = 0; i < pizzas.size(); i++) {
        if (given.find(pizzas[i].index) == given.end()) {
            tmp = ingr_union(pizzas[i].ingredients,s);
            if (tmp.size() > best) {
                best = tmp.size();
                ret = tmp;
                *new_idx = i;
            }
        }
    }
    return ret;
}

set<string> find_first_2(vector<Pizza> &pizzas, unsigned int *idx1, unsigned int *idx2) {
    set<string> ret,tmp;
    unsigned int best = 0,tmpIdx;
    *idx1 = *idx2 = 0;
    for (unsigned int i = 0; i < pizzas.size(); i++) {
        if (given.find(pizzas[i].index) == given.end()) {
            given.insert(pizzas[i].index);
            tmp = find_best_union(pizzas,pizzas[i].ingredients,&tmpIdx);
            given.erase(pizzas[i].index);
            if (tmp.size() > best) {
                best = tmp.size();
                ret = tmp;
                *idx1 = i;
                *idx2 = tmpIdx;
            }
        }
    }
    return ret;
}

int main(int argc,char *args[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    unsigned int M,T2,T3,T4;
    vector<Pizza> pizzas;

    cin >> M >> T2 >> T3 >> T4;
    
    unsigned int I;
    string ingredient;
    for (unsigned int i = 0; i < M; i++) {
        cin >> I;
        set<string> curPizza;
        for (unsigned int j = 0; j < I; j++) {
            cin >> ingredient;
            curPizza.insert(ingredient);
        }
        pizzas.push_back({i,curPizza});
    }

    sort(pizzas.begin(),pizzas.end(),pizzacmp);

    unsigned int D = 0;
    
    unsigned int idx[3][4];
    // Groups of 4
    for (unsigned int i = 0;M >= 4 && i < T4; i++) {
        set<string> best = find_first_2(pizzas,&idx[2][0],&idx[2][1]);
        given.insert(idx[2][0]);
        given.insert(idx[2][1]);
        for (unsigned int j = 2;best.size() > 0 && j < 4; j++) {
            best = find_best_union(pizzas,best,&idx[2][j]);
            given.insert(idx[2][j]);
        }
        if (best.size() > 0) {
            cout << 4 << " ";
            for (unsigned int j = 0;j < 4;j++) {
                cout << idx[2][j] << " ";
            }
            cout << endl;
            M -= 4;
            D++;
        } 
    }

    // Groups of 3
    for (unsigned int i = 0;M >= 3 && i < T3; i++) {
        set<string> best = find_first_2(pizzas,&idx[1][0],&idx[1][1]);
        given.insert(idx[1][0]);
        given.insert(idx[1][1]);
        for (unsigned int j = 2;best.size() > 0 && j < 3; j++) {
            best = find_best_union(pizzas,best,&idx[1][j]);
            given.insert(idx[1][j]);
        }
        if (best.size() > 0) {
            cout << 3 << " ";
            for (unsigned int j = 0;j < 3;j++) {
                cout << idx[1][j] << " ";
            }
            cout << endl;
            M -= 3;
            D++;
        } 
    }

    // Groups of 2
    for (unsigned int i = 0;M >= 2 && i < T2; i++) {
        set<string> best = find_first_2(pizzas,&idx[0][0],&idx[0][1]);
        given.insert(idx[0][0]);
        given.insert(idx[0][1]);
        if (best.size() > 0) {
            cout << 2 << " ";
            for (unsigned int j = 0;j < 2;j++) {
                cout << idx[0][j] << " ";
            }
            cout << endl;
            M -= 2;
            D++;
        } 
    }
    cout << D << endl;

    return 0;
}



