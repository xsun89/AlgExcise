#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef struct _point {
    int x;
    int y;
} POINT;

int maxNumberPointsInLine(vector<POINT> &p) {
    if(p.size() <=1){
        return p.size();
    }
    int res = 0;
    for (int i = 0; i < p.size(); i++) {
        int curPoint = 1;
        int dupPoint = 0;
        int verticalPoint = 0;
        map<double, int> m;
        for (int j = i + 1; j < p.size(); j++) {
            if (p[i].x == p[j].x) {
                if (p[i].y == p[j].y) {
                    dupPoint++;
                } else {
                    verticalPoint++;
                }
            } else {
                double k = (p[j].y - p[i].y) / (p[j].x - p[i].x);
                m[k] == 0 ? m[k] = 2 : m[k]++;
                curPoint = max(curPoint, m[k]);
            }
        }
        curPoint = max(curPoint + dupPoint, dupPoint + verticalPoint + 1);
        res = max(res, curPoint);
    }
    return res;
}

int main() {
    return 0;
}
