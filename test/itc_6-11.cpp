#include <iostream>
#include "easy.h"

using namespace std;

bool itc_iseven(int num){
    if(num % 2 != 0)
        return false;
    return true;
}

int itc_max(int num, int num2){
    if(num > num2)
        return num;
    return num2;
}

int itc_min(int num1, int num2){
    if(num1 > num2)
        return num2;
    return num1;
}

double itc_fmax(double num, double num2){
    if(num > num2)
        return num;
    return num2;
}

double itc_fmin(double num, double num2){
    if(num < num2)
        return num;
    return num2;
}

int itc_sqrt(int num){
    int z = -1;
    for(int i = 0; i <= num; ++i){
        if(i*i == num)
            z = i;
    }
    return z;
}
