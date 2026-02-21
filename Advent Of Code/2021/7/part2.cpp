#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc,char *args[]) {
    string numS;
    vector<int> nums;
    int maxN = -1;
    while (getline(cin, numS, ',')) {
        nums.push_back(atoi(numS.c_str()));
        maxN = max(maxN, atoi(numS.c_str()));
    }
    int ans = INT32_MAX;
    for (int i = 0; i <= maxN; i++) {
        int tmp = 0;
        for (int j = 0;j < nums.size(); j++) {
            tmp+=abs(nums[j]-i)*(abs(nums[j]-i)+1)/2;
        }
        ans=min(ans, tmp);
    }
    
    cout << ans << endl;
    return 0;
}