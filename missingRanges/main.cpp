#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
void missingRange(const vector<int>& source, int lower, int upper, vector<string>* ret){
    int sz = source.size();
    int prev = lower -1;
    int current = 0;
    int j = 0;

    for(int i=0; i<=sz; i++){
        if(i == sz){
            current = upper + 1;
        }else{
            current = source[i];
        }
        if(current - prev >= 2){
            int misStart = prev + 1;
            int misEnd = current -1;
            stringstream sStart;
            stringstream sEnd;
            sStart << misStart;
            string prevStr = sStart.str();
            sEnd << misEnd;
            string curStr = sEnd.str();
            string retStr;
            if(misStart == misEnd){
                retStr = prevStr;
            }else{
                retStr = prevStr + "->" + curStr;
            }
            (*ret).push_back(retStr);
            prev = current;
        }else {
            prev = current;
        }


    }


}

int main() {
    vector<int> source = {0, 1, 3, 50, 75};
    vector<string> ret;
    missingRange(source, 0, 99, &ret);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }
    return 0;
}
