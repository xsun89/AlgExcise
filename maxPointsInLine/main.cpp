#include <iostream>
#include <vector>
#include <map>
//#include <bits/unordered_map.h>

using namespace std;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) { }

    Point(int a, int b) : x(a), y(b) { }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        if (size <= 1) return size;
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int local = 1;
            int Vertical = 0;
            int Dup = 0;
            double k = 0.0;
            map<double, int> map;
            for (int j = i + 1; j < size; ++j) {
                //ֻ���i+1���ֵ�ĵ����ߣ���Ϊ��֮ǰΪС��i+1����ֱ���Ѿ�������i+1�㣬���������ظ�������
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) Dup++;
                        //ͳ���ظ��ĵ���
                    else Vertical++;
                    //ͳ��ˮƽ�ĵ���
                } else {
                    k = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
                    map[k] == 0 ? map[k] = 2 : map[k]++;
                    //������ͬһֱ���ϵĵ�
                    local = max(local, map[k]);
                    //�͸ýڵ���ͬһֱ���ϵ�������
                }
            }
            local = max(local + Dup, Vertical + Dup + 1);
            //�ýڵ�����ظ��Ľڵ㣬ע��ˮƽ���ظ��ڵ��п��������ֵ
            res = max(local, res);
            //�������н��е����Ľڵ�
        }
        return res;
    }
};

int main() {
    return 0;
}
