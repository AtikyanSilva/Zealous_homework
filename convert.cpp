#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int degree(int a, int b){
    int a_copy = a;
    if(b == 0){
        return 1;
    }
    for(int i = 0; i < b - 1; i++){
        a *= a_copy;
    }
    return a;
}
int make_10(string num, int base1){
    reverse(num.begin(), num.end());
    int result = 0;
    for(int i = 0; i < num.length(); i++){
        if(num[i] - '0' >= base1){
            return -1;
        }
        result += (num[i] - '0') * degree(base1, i);
    }
    return result;
}
string make_desiredBase(int result, int base2){
    string answer = "";
    if(result == -1){
        return "-1";
    }
    while(result > base2 - 1){
        answer += to_string(result % base2);
        result /= base2;
    }
    answer += to_string(result);
    reverse(answer.begin(), answer.end());
    return answer;
}
string convert(string num, int base1, int base2){
    int result = make_10(num, base1);
    return make_desiredBase(result, base2);
}

int main()
{
    cout << convert("100780", 9, 7);
    return 0;
}