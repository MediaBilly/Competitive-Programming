#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc,char *args[]) {
    string numS;
    vector<int> nums;
    while (getline(cin, numS, ',')) {
        nums.push_back(atoi(numS.c_str()));
    }
    sort(nums.begin(), nums.end());
    int median = nums[nums.size()/2];
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans+=abs(nums[i]-median);
    }
    
    cout << ans << endl;
    return 0;
}