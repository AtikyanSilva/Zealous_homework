#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool fizz(int num){
    int sumOfNum = 0; 
    while(num != 0){
        sumOfNum += num % 10;
        num /= 10;}
    if(sumOfNum % 3 == 0){
        return true;
    } 
    else{
        return false;
    }
};
int main(){
    vector<string> result;
    for(int i = 1; i <= 50; i++){
        if(fizz(i) and i % 5 == 0){
            result.push_back("FizzBuzz");
        }
        else if(fizz(i)){
            result.push_back("Fizz");
        }
        else if(i % 5 == 0){
            result.push_back("Buzz");
        }
        else{
            result.push_back(to_string(i));
        }
    }
    for(int i = 0; i < 50; i++){
        cout << result[i] << " ";
    }
}