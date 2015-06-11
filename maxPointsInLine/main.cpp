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
                //只需对i+1大的值的点求线，因为以之前为小于i+1起点的直线已经遍历过i+1点，再求解就是重复遍历了
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) Dup++;
                        //统计重复的点数
                    else Vertical++;
                    //统计水平的点数
                } else {
                    k = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
                    map[k] == 0 ? map[k] = 2 : map[k]++;
                    //计算在同一直线上的点
                    local = max(local, map[k]);
                    //和该节点在同一直线上的最大点数
                }
            }
            local = max(local + Dup, Vertical + Dup + 1);
            //该节点加上重复的节点，注意水平和重复节点有可能是最大值
            res = max(local, res);
            //计算所有解中的最大的节点
        }
        return res;
    }
};

int main() {
    return 0;
}
