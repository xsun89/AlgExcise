#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findSum(const vector<int>& source, int target)
{
    vector<int> index(2);
    int size = (int)source.size();
    for(int i=0; i<size; i++){
        index[0] = i;
        for(int j=i+1; j<size;j++){
            if(source[i] + source[j] == target){
                index[1] = j;
                return index;
            }
        }
    }

    return index;

}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> index(2);
    int n = (int)nums.size();
    map<int,int> mapv;
    for(int i = 0; i < n ; i++) {
        mapv[nums[i]] = i;
    }
    map<int,int>::iterator it;
    for(int i = 0; i < n; i++) {
        index[0] = i;
        it = mapv.find(target - nums[i]);
        if(it != mapv.end() && i != it->second){
            index[1]=it->second;
            break;
        }
    }
    return index;
}

int main() {
    vector<int> source = {1, 3, 5, 3, 2, 4};
    int target = 7;

    vector<int> ret = findSum(source, target);
    vector<int> ret2 = twoSum(source, target);
    for(int k=0; k<2; k++){
        cout << ret[k] << endl;
        cout << ret2[k] << endl;
    }
    return 0;
}