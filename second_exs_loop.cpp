#include <iostream>
#include <unordered_map>
using namespace std;
bool isAnagram(string first, string second){
    if(first.length() != second.length()){
        return false;
    }
    bool isSame = false;
    if(first.length() > second.length())
    for (int i = 0; i < first.length(); i++) {
        isSame = false;
        for (int j = 0; j < second.length(); j++) {
            if(first[i] == second[j]){
                isSame = true;
            }
        }
        if(!isSame){
            return false;
        }
    }
    return true;
}
int main()
{
    int countOfStr;
    cout << "Ներմուծեք բառերի քանակը: ";
    cin >> countOfStr;
    string words[countOfStr];
    cout << "Ներմուծեք բառերը։ ";
    for (int i = 0; i < countOfStr; i++) {
        cin >> words[i];
    }
    for (int i = 0; i < countOfStr; i++) {
        if(words[i] == "Already taken"){
            continue;
        }
        cout << "[" << words[i];
        for (int j = i + 1; j < countOfStr; j++) {
            if(isAnagram(words[i], words[j])){
                cout <<  ", " << words[j];
                words[j] = "Already taken";
            }
        }
        cout << "]";
    }
    return 0;
}