#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
long long Factorial(long long num){
    if(num <= 1){
        return 1;
    }
    return num * Factorial(num - 1);
}
int main(){
    cout << Factorial(19) << endl;
    return 0;
}