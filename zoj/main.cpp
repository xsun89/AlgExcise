#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <stdio.h>

using namespace std;
bool iszoj(const char *source) {
    bool isZ = false;
    bool isO = false;
    bool isJ = false;
    int len = strlen(source);
    int i = 0;
    while(i<len){
        if(i==0 && source[i] == 'z'){
            isZ = true;
        }
        if(i==1 && source[i] == 'o'){
            isO = true;
        }
        if(i==2 && source[i] == 'j'){
            isJ = true;
        }

        i++;
    }
    if (isZ && isO && isJ && i==3) {
        return true;
    }

    return false;
}
bool isxzojx(const char *source) {
    int len = strlen(source);
    int i = 0;
    int numberZ = 0;
    int positionZ = -1;
    int numberJ = 0;
    int numberO = 0;
    int positionJ = -1;
    int positionO = -1;
    bool ret = true;
    while (i < len) {
        if (source[i] == 'z') {
            numberZ++;
            positionZ = i;
        }
        if (source[i] == 'j') {
            numberJ++;
            positionJ = i;
        }
        /*
        if (i > positionZ && source[i] == 'o') {
            numberO++;
            positionO = i;
        }
        */
        i++;
    }
    int k = 0;
    int h = len-1;
    for(;k<positionZ && h>positionJ;k++,h--){
        if(source[k] != source[h]){
            ret = false;
        }
        if(source[k] != 'o' && source[k] != ' '){
            ret = false;
        }
    }

    if (numberJ != 1 || numberZ != 1 || positionJ - positionZ != 2 || source[positionZ+1] != 'o') {
        ret = false;
    }

    return ret;
}
bool isazbojac(const char *source) {
    int len = strlen(source);
    int i = 0;
    int numberZ = 0;
    int positionZ = -1;
    int numberJ = 0;
    int numberO = 0;
    int positionJ = -1;
    int positionO = -1;
    int numberA = 0;
    int numberB = 0;
    int numberC = 0;
    bool isZ = false;
    bool isJ = false;
    bool ret = true;
    while (i < len) {
        if (source[i] == 'z') {
            numberZ++;
            positionZ = i;
            isZ = true;
        }
        if (source[i] == 'j') {
            numberJ++;
            positionJ = i;
            isJ = true;
        }

        if (isZ == false && isJ == false && source[i] == 'o') {
            numberA++;
        }
        if(isZ == true && isJ == false && source[i] == 'o'){
            numberB++;
        }
        if(isZ == true && isJ == true && source[i] == 'o'){
            numberC++;
        }
        i++;
    }

    if (numberJ != 1 || numberZ != 1 || numberB < 1 || numberC != 2*numberA) {
        ret = false;
    }

    return ret;
}
int main() {
    char source[100];
    cin >> source;
    bool ret;
    //bool ret = iszoj(source);
    //cout << ret << endl;
    ret = isxzojx(source);
    cout << ret << endl;
    return 0;
}