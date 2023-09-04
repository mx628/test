#include <iostream>
#include "easy.h"

using namespace std;

int itc_revnbr(int num){
    return num % 10 * 100 + num / 10 % 10 * 10 + num / 100;
}
