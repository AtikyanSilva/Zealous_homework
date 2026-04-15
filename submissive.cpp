#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<char, int> v;
    string s = "";
    int max = 0;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char char1 = s[i];
        if(v.find(char1) == v.end()){
            v[char1] = i;
            count++;
        }
        else{
            if(count > max){
                max = count;
            }
            auto it = v.find(char1);
            count = i - it->second;
            v.clear();
            v[char1] = i;
        }
        
    }
    if(count > max){
        max = count;
            }
    cout << max;
    return 0;
}