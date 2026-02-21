#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

typedef struct 
{
    int id;
    vector<string> roadsIncoming;
} Intersection;

typedef struct 
{
    int B,E;
    string name;
    int L;
    bool isGreen;
    vector<int> cars;
} Street;

typedef struct 
{
    int id;
    vector<string> paths;
} Car;

typedef struct 
{
    int intersection;
    vector<pair<string,int>> timePerIncStreet; 
} Schedule;

typedef struct 
{
    vector<Intersection> intersections;
    unordered_map<string,Street> streets;
    vector<Car> cars;
    unsigned int cur_time = 0;
} Graph;

Graph roadNet;

int main(int argc,char *args[]) {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read Input
    int D,I,S,V,F,P;
    cin >> D >> I >> S >> V >> F;
    Street s;
    Intersection intr;
    string rname;
    for (int i = 0; i < I; i++) {
        intr.id = i;
        roadNet.intersections.push_back(intr);
    }
    for (int i = 0; i < S; i++) {
        cin >> s.B >> s.E >> s.name >> s.L;
        s.isGreen = false;
        roadNet.streets[s.name] = s;
        roadNet.intersections[s.E].roadsIncoming.push_back(s.name);
    }
    for (int i = 0; i < V; i++) {
        vector<string> paths;
        cin >> P;
        for (int j = 0; j < P; j++) {
            cin >> rname;
            paths.push_back(rname);
        }
        roadNet.cars.push_back({i,paths});
        roadNet.streets[rname].cars.push_back(i);
    }

    // Generate schedules
    vector<Schedule> schedules;
    for (int i = 0;i < roadNet.intersections.size();i++) {
        Schedule sch;
        sch.intersection = i;
        sch.timePerIncStreet.clear();
        int roads = roadNet.intersections[i].roadsIncoming.size();
        pair<string,int> tmpP;
        for (int j = 0;j < roads;j++) {
            tmpP.first = roadNet.intersections[i].roadsIncoming[j];
            int lightSecs = roadNet.streets[tmpP.first].cars.size();
            tmpP.second = lightSecs + rand() % ((D - lightSecs)) + 1;
            sch.timePerIncStreet.push_back(tmpP);
        }
        schedules.push_back(sch);
    }

    // Output Schedules
    cout << schedules.size() << endl;
    for (unsigned int i = 0;i < schedules.size();i++) {
        cout << schedules[i].intersection << endl;
        cout << schedules[i].timePerIncStreet.size() << endl;
        for (int j = 0;j < schedules[i].timePerIncStreet.size();j++) {
            cout << schedules[i].timePerIncStreet[j].first << " " << schedules[i].timePerIncStreet[j].second << endl;
        }
    }

    return 0;
}