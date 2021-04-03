#include <bits/stdc++.h>

using namespace std;

int digits(unsigned long long N) {
    int ret=0;
    while (N > 0) {
        ret++;
        N/=10;
    }
    return ret;
}

unsigned long long pow10(int p) {
    if (p == 0) {
        return 1;
    }
    if (p == 1) {
        return 10;
    }
    unsigned long long tmp = pow10(p/2); 
    tmp *= tmp;
    if (p % 2 != 0) {
        tmp *= 10;
    }
    return tmp;
}

long long myabs(long long N) {
    return N >= 0 ? N : -N;
}

unsigned long long ans1(unsigned long long N) {
    unsigned long long p = pow10(digits(N)-1);
    while (p > 0) {
        if ((N / p) % 2 != 0) {
            N -= p;
            p /= 10;
            break;
        }
        p /= 10;
    }
    while (p > 0) {
        if (p != 1) {
            N += (8 - N % (10 * p)/p) * p;
        } else {
            N += 8 - N % 10;
        }
        p /= 10;
    }
    return N;
}

unsigned long long ans2(unsigned long long N) {
    unsigned long long p = 1,curDigit;
    while (p <= N) {
        curDigit = N % (10 * p)/p;
        if (curDigit % 2 != 0) {
            N += p - N % p;
        }
        p *= 10;
    }
    return N;
}

void solve(int x) {
    unsigned long long N,ans;
    cin >> N;
    cout << "Case #" << x << ": " << min(myabs(N-ans1(N)),myabs(N-ans2(N))) << endl;
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
