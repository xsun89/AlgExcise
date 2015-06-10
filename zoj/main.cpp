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
    int numberZ = 0;
    int positionZ = -1;
    int numberJ = 0;
    int positionJ = -1;
    while (i < len) {
        if (source[i] == 'z') {
            numberZ++;
            positionZ = i;
        }
        if (source[i] == 'j') {
            numberJ++;
            positionJ = i;
        }
        if (source[i] == 'j' && i == 2) {
            isJ = true;
        }
        i++;
    }

    if (numberJ == 1 && numberZ == 1 && positionJ - positionZ >= 1) {
        return true;
    }

    return false;
}

int main() {
    char source[100];
    cin >> source;
    bool ret = iszoj(source);
    cout << ret << endl;
    return 0;
}