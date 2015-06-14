#include <iostream>
#include <vector>
#include <map>

using namespace std;
int getMin(vector<int>& s){
    int m = s.size();
    int ret = s[0];

    for(int i=1; i<m; i++){
        if(s[i]<ret){
            ret = s[i];
        }
    }

    return ret;
}

int minimalTotal(vector<vector<int>>& triangle){
    int sz = triangle.size();
    if(sz == 0){
        return 0;
    }
    vector<vector<int>> dp;
    dp.resize(sz);
    dp[0].resize(1);
    dp[0][0] = triangle[0][0];
    for(int i=1; i<sz; i++){
        int xTotalSize = triangle[i].size();
        dp[i].resize(xTotalSize);
        for(int j=0; j<xTotalSize;j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }else if(j==xTotalSize-1){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }else{
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }

    int ret = getMin(dp[sz-1]);
    return ret;
}


int main() {
    vector<int> a0 = {2};
    vector<int> a1 = {3, 4};
    vector<int> a2 = {6, 5, 7};
    vector<int> a3 = {4, 1, 8, 3};

    vector<vector<int>> source = {a0, a1, a2, a3};

    int ret = minimalTotal(source);

    cout << ret << endl;
    return 0;
}