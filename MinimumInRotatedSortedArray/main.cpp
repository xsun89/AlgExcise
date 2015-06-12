#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int findMinimun(vector<int> &source) {
    int left = 0;
    int right = source.size() - 1;
    while (left < right) {
        if (source[left] < source[right]) {
            break;
        }
        int mid = (left + right) / 2;
        if (source[mid] > source[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return source[left];
}



int main() {
    vector<int> source = {4, 5, 6, 7, 0, 1, 2, 3};
    int ret = findMinimun(source);

    cout << ret << endl;
    return 0;
}