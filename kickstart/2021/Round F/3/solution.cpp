#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
} star;

bool cmpx( star s1, star s2) {
    return s1.x < s2.x;
}

bool cmpy( star s1, star s2) {
    return s1.y < s2.y;
}

double dist(star a, star b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * ((a.y - b.y)));
}

const double INF = 1.0/0.0;

void solve(int x) {
    int N;
    cin >> N;
    vector<star> starsByX, starsByY;
    star s;
    star blue;
    for (int i = 0; i < N; i++) {
        cin >> s.x >> s.y;
        starsByX.push_back(s);
    }
    cin >> blue.x >> blue.y;
    starsByY = starsByX;
    sort(starsByX.begin(), starsByX.end(), cmpx);
    sort(starsByY.begin(), starsByY.end(), cmpy);

    if (N <= 2 || blue.x < starsByX[0].x || blue.x > starsByX[N-1].x || blue.y < starsByY[0].y || blue.y > starsByY[N-1].y ) {
        cout << "Case #" << x << ": " << "IMPOSSIBLE" << endl;
        return;
    }

    // Find 3 closest
    star s1, s2, s3;
    s1 = s2 = s3 = starsByX[0];
    double d1 = INF, d2 = INF, d3 = INF;

    for (int i = 1; i < N; i++) {
        if (dist(blue, starsByX[i]) < d1) {
            s3 = s2;
            d3 = d2;
            s2 = s1;
            d2 = d1;
            s1 =starsByX[i];
            d1 = dist(blue, starsByX[i]);
        } else if (dist(blue, starsByX[i]) < d2) {
            s3 = s2;
            d3 = d2;
            s2 =starsByX[i];
            d2 = dist(blue, starsByX[i]);
        }
        else if (dist(blue, starsByX[i]) < d3) {
            s3 =starsByX[i];
            d3 = dist(blue, starsByX[i]);
        }
    }
    
    
    cout.precision(10);
    int ans = 0;
    cout << "Case #" << x << ": " << dist(s1,s2) + dist(s2,s3) + dist(s3, s1) << endl;
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
