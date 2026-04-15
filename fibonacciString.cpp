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
string whichFibonachi(string num){
    string firstFibonachi = "1";
    string secondFibonachi = "1";
    string count = "1";
    string temp = "0";
    if(num != "1"){
    count = "2";
    }
    while((secondFibonachi.length() == num.length() and secondFibonachi < num) or secondFibonachi.length() < num.length()){
        temp = secondFibonachi;
        secondFibonachi = sum(secondFibonachi, firstFibonachi);
        firstFibonachi = temp;
        count = sum(count, "1");
    }
    if(secondFibonachi == num){
        return count;
    }
    return "-1";
}
int main()
{
    cout << whichFibonachi("43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875") << endl;
    cout << "4 is " << whichFibonachi("4") << endl;
    cout << "1 is " << whichFibonachi("1") << endl;
    return 0;
}