#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
string subtraction(string a, string b){
    string result_final = "";
    string current_result = "";
    int borrow = 0;
    bool swap1 = false;
    if(a.length() < b.length() || (a.length() == b.length() && a < b)) { // Եթե առաջին թիվը փոքր է, փոխում եմ երկրորրդի հետ
    swap1 = true; // Նշում եմ, որ փոխել եմ, որպեսզի վերջում '-' -ով վերադարձվի
    swap(a, b);
    }
    if(a.length() > b.length()){ // Հավասարեցնում եմ թվերի երկարությունը ավելացնելով 0-ներ
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
        if((a[i] - '0') - borrow < (b[i] - '0')){ // Եթե առաջին թվի համապատասխան նիշը փոքր է երկրորրդինից
            result_final += to_string((10 + (a[i] - '0') - borrow - (b[i] - '0')) % 10); // 10 ենք վերցնում նախորրդից և այդ տարբերությունը ավելացնում
            borrow = 1; // Նշում ենք, որ վերցրել ենք
        }
        else{
            result_final += to_string((a[i] - '0') - borrow - (b[i] - '0')); // Հակառակ դեպքում, ուղղակի ավելացնում ենք տարբերությունը
            borrow = 0; // Նշում, որ արդեն հանել ենք վերցրվածը
        }
    }
    reverse(result_final.begin(), result_final.end());
    if(swap1){
        return "-" + result_final;
    }
    return result_final;
}
int main()
{
    cout << subtraction("15", "55555555555555555555555555555555555555") << endl;
    return 0;
}