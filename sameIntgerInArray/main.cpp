#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findTwoSameIntegers(vector<int>& nums, int target) {
    int n = (int)nums.size();
    map<int,int> mapv = {};
    int i;
    int ret = 0;
    map<int,int>::iterator it;
    for(i = 0; i < n; i++) {
        it = mapv.find(nums[i]);
        if(it != mapv.end() && i - it->second < target){
            ret = i;
            break;
        } else{
            mapv[nums[i]] = i;
        }
    }
    return ret;
}

int main() {
    vector<int> source = {1, 3, 5, 3, 2, 4};
    int target = 1;

    int ret = findTwoSameIntegers(source, target);

    cout << ret << endl;
    return 0;
}