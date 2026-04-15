#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
string sum(string a, string b){
    string result_final = "";
    int result1 = 0;
    if(a.length() > b.length()){ 
        reverse(b.begin(), b.end());
        while(a.length() != b.length()){
            b += '0';
        }
        reverse(b.begin(), b.end());
    }
    else if(b.length() > a.length()){
        reverse(a.begin(), a.end());
        while(a.length() != b.length()){
            a += '0';
        }
        reverse(a.begin(), a.end());
    }
    for(int i = a.length() - 1; i >= 0; i--){
        result_final += to_string(((a[i] - '0') + (b[i] - '0') + result1) % 10); 
        result1 = ((a[i] - '0') + (b[i] - '0') + result1) / 10; 
    }
    if(result1){
        result_final += to_string(result1);}
    reverse(result_final.begin(), result_final.end()); 
    return result_final;
}
string nextFibonacci(string first, string second, string num, string count){
    count = sum(count, "1");
    if(second == num){
        return count;
    }
    if((second.length() == num.length() and second > num) or second.length() > num.length()){
        return "-1";
    }
    string temp = second;
    second = sum(second, first);
    first = temp;
    return nextFibonacci(first, second, num, count);
}
string whichFibonacci(string num){
    if(num == "1"){
        return "1";
    }
    return nextFibonacci("1", "1", num, "1");
}
int main()
{
    cout << whichFibonacci("43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875") << endl;
    cout << "4 is " << whichFibonacci("4") << endl;
    cout << "1 is " << whichFibonacci("1") << endl;
    cout << "8 is " << whichFibonacci("1") << endl;
    return 0;
}