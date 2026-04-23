#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
void firstSolution(string& code_copy){ // First of all, I convert the digit code into an alphabet code and check if the code is valid or not 
    bool isPossible = true;
    for(int i = 0; i < code_copy.length(); i++){
        if(code_copy[i] - '0' > 0 and code_copy[i] - '0' <= 9){
            code_copy[i] = char('A' + (code_copy[i] - '0') - 1);
        }
        else{
            if(i == 0){
                cout << "Invalid code" << endl;
                code_copy = "";
                return;
            }
            if(code_copy[i - 1] > 'B'){
                cout << "Invalid code" << endl;
                code_copy = "";
                return;
            }
            if(code_copy[i - 1] == 'A'){
                code_copy[i - 1] = ' ';
                code_copy[i] = char('A' + 9);
            }
            else if(code_copy[i - 1] == 'B'){
                code_copy[i - 1] = ' ';
                code_copy[i] = char('A' + 19);
            }
        }
    }
}
void findAllSolution(vector<string>& result, string code, int first){ // I found all combinations of the alphabet code (exp. "AB" -> 12 -> "L")
    string code_copy = code;
    for(int i = first; i < code_copy.length() - 1; i++){
        if(code_copy[i] == ' '){
            continue;
        }
        if(code_copy[i] == 'A'){
            if(((code_copy[i] - '0') + (code_copy[i + 1] - '0')) <= 42){
                code_copy[i] = char('A' + (('A' - '0') + (code_copy[i + 1] - '0') - 24));
                code_copy[i + 1] = ' ';
                result.push_back(code_copy);
                findAllSolution(result, code, first + 1);
                findAllSolution(result, code, first + 2);
            }
        }
        if(code_copy[i] == 'B'){
            if(((code_copy[i] - '0') + (code_copy[i + 1] - '0')) <= 40){
                code_copy[i] = char('A' + (('B' - '0') + (code_copy[i + 1] - '0') - 15));
                code_copy[i + 1] = ' ';
                result.push_back(code_copy);
                findAllSolution(result, code, first + 1);
                findAllSolution(result, code, first + 2);
            }
        }
        }
    return;
}
int main(){
    vector<string> result;
    string code = "";
    cout << "Please enter the code: ";
    getline(cin, code);
    for(int i = 0; i < code.length(); i++){
        if(!isdigit(code[i])){
            cout << "Invalid input!" << endl;
            return 0;
        }
    }
    firstSolution(code);
    result.push_back(code);
    findAllSolution(result, code, 0);
    bool isRight = true;
    set<string> finalResult(result.begin(), result.end());
    int count = 0;
    for(string line : finalResult){
        isRight = true;
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        for(int i = 0; i < line.length(); i++){
            if(!isalpha(line[i])){
                isRight = false;
            }
        }
        if(isRight){
            count++;
            cout << line << endl;
        }
    }
    cout << "The possible version is: " + to_string(count);
}
