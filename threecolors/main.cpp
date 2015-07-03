#include <iostream>
#include <vector>
#include <map>

using namespace std;

void sortThreeColors(int *colorArray, int num){
    int p0 = 0;
    int p1 = num -1;
    int i = 0;

    while(i <= p1){
        if(colorArray[i] == 2){
            int tmp = colorArray[i];
            colorArray[i] = colorArray[p1];
            colorArray[p1] = tmp;
            p1--;
        }else if(colorArray[i] == 0 && p0 < i){
            int tmp = colorArray[i];
            colorArray[i] = colorArray[p0];
            colorArray[p0] = tmp;
            p0++;
        }else{
            i++;
        }
    }
}

int main() {

    int nArray[] = { 2, 0, 2, 0, 1, 1 };
    sortThreeColors( nArray, 6 );

    for( int i = 0; i < 6; ++i )
    {
        cout << nArray[i] << " ";
    }
    cout << endl;



    return 0;
}