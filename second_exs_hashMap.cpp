#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void swap(char &first, char &second){
    char t = first;
    first = second;
    second = t;
}
string sort(string word){
    for (int i = 0; i < word.length() - 1; i++) {
        for (int j = 0; j < word.length() - 1 - i; j++) {
            if(word[j] > word[j + 1]){
                swap(word[j], word[j + 1]);
            }
        }
    }
    return word;
}
int main()
{
    int countOfStr;
    cout << "Ներմուծեք բառերի քանակը: ";
    cin >> countOfStr;
    unordered_map<string, string> anagrams;
    cout << "Ներմուծեք բառերը։ ";
    for (int i = 0; i < countOfStr; i++) {
        string word;
        cin >> word;
        string key = sort(word); 
        if (anagrams.find(key) == anagrams.end())
            anagrams[key] = word;
        else
            anagrams[key] += ", " + word;
    } 
    for(auto anagram : anagrams){
        cout << "[" << anagram.second << "], ";
    }
    return 0;
}