#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
string sum(string a, string b){
    string result_final = "";
    int result = 0;
    int result1 = 0;
    if(a.length() > b.length()){ // ԵԹե երկարությունները հավասար չեն, ավելացնում եմ սկզբից 0-ներ
        reverse(b.begin(), b.end()); // Սկզբում շրջում եմ, որպեսզի վերջից ավելացնելուց հետո կրկին շրջեմ և թիվը նույնը մնա
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
        result_final += to_string(((a[i] - '0') + (b[i] - '0')) % 10 + result1); // Ացելացնում եմ մնացորդը + նախորդ գումարից ստացված ամբողջ մասը
        result1 = ((a[i] - '0') + (b[i] - '0')) / 10; // Պահում եմ ամբողջ մասը 
    }
    reverse(result_final.begin(), result_final.end()); // Վերջում շրջում, քանզի թվերը սկզբից էին ավելացել 
    return result_final;
}
int main()
{
    cout << sum("2222222222222222222222222", "3333333333333333333333333") << endl;
    return 0;
}