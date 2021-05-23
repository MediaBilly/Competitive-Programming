#include <bits/stdc++.h>

using namespace std;

bool prime[100001];

void solve(int x) {
    int Z;
    cin >> Z;
    vector<unsigned long long> primes;
    int N = min(100000,Z);
    int p = 2;
    primes.push_back(p);
    int i=0;
    for (p = 3; p <= N; p++) {
        if (prime[p]) {
            primes.push_back(p);
            if (primes[i] * primes[i+1] > Z) {
                cout << "Case #" << x << ": " << primes[i-1] * primes[i] << endl;
                return;
            } else {
                i++;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    memset(prime,true,sizeof(prime));
    for (int p = 2; p * p <= 100000;) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 100000; i += p)
                prime[i] = false;
        }
        if (p > 2) {
            p+=2;
        } else {
            p++;
        }
    }
    for (int i = 1;i <= T;i++) {
        solve(i);
    }
    return 0;
}
