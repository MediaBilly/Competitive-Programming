#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

class Bingo {
    private:
        bool rowWins(int row) {
            for (int i = 0; i < 5; i++) {
                if (!this->marked[row][i]) {
                    return false;
                }
            }
            this->won = true;
            return true;
        }
        bool colWins(int col) {
           for (int i = 0; i < 5; i++) {
                if (!this->marked[i][col]) {
                    return false;
                }
            }
            this->won = true;
            return true;
        }
    public:
        int board[5][5];
        bool marked[5][5];
        bool won;
        Bingo() {
            this->won = false;
            memset(this->marked, false, sizeof(this->marked));
        }
        void addNum(int row, int col, int num) {
            this->board[row][col] = num;
        }
        bool markNum(int num) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (this->board[i][j]==num) {
                        this->marked[i][j]=true;
                        if (rowWins(i) || colWins(j)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        int score() {
            int sc = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (!this->marked[i][j]) {
                        sc+=this->board[i][j];
                    }
                }
            }
            return sc;
        }
};


int main(int argc,char *args[]) {
    // Read query numbers
    string qStr;
    getline(cin, qStr, '\n');
    vector<int> query;
    stringstream qStream(qStr);
    string numS;
    while (getline(qStream, numS, ',')) {
        query.push_back(atoi(numS.c_str()));
    }

    // Read bingo boards
    vector<Bingo> bingos;
    while (getline(cin, qStr, '\n')) {
        Bingo b;
        int num;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> num;
                b.addNum(i, j, num);
            }
        }
        bingos.push_back(b);
    }

    // Simulation
    int lastWon, lastWonQuery, wonCnt=0;
    for (int q: query) {
        for (int b = 0; b < bingos.size(); b++) {
            if (!bingos[b].won && bingos[b].markNum(q)) {
                lastWon = b;
                lastWonQuery = q;
            }
        }
    }
    cout << bingos[lastWon].score() * lastWonQuery;
    return 0;
}