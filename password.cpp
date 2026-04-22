#include <iostream>
#include <string>
using namespace std;
class strengthPassword{
    private:
    string password = "";
    public:
    strengthPassword(string password1){
        password = password1; 
    }
    void whichPassword(){
        if(password.length() > 32 or password.length() < 4){
            cout << "Invalid input" << endl;
            return;
        }
        if(password.length() <= 6){
            for(int i = 0; i < password.length(); i++){
                if(password[i] == ' '){
                    cout << "Invalid input" << endl;
                    return;
                }
            }
            cout << "The password is weak" << endl;
            return;
        }
        int count = 0;
        bool findDigit = false;
        bool findSymbols = false;
        bool findUppercase = false;
        bool findLowercase = false;
        for(int i = 0; i < password.length(); i++){
            if(password[i] == ' '){
                cout << "Invalid input" << endl;
                return;
            }
            if(!findDigit){
                if(isdigit(password[i])){
                    count++;
                    findDigit = true;
                }
            }
            if(!findSymbols){
                if(!isdigit(password[i]) and !isalpha(password[i])){
                    count++;
                    findSymbols = true;
                }
            }
            if(!findLowercase){
                if(isalpha(password[i]) and isupper(password[i])){
                    count++;
                    findLowercase = true;
                }
            }
            if(!findUppercase){
                if(isalpha(password[i]) and !isupper(password[i])){
                    count++;
                    findUppercase = true;
                }
            }
    }
    if(count < 4 and count > 1){
        cout << "Medium" << endl;
        return;
    }
    if(count == 1){
        cout << "Weak" << endl;
        return;
    }
    cout << "Strong";
}};
int main(){
    cout << "Please enter the password: ";
    string password;
    getline(cin, password);
    strengthPassword user(password);
    user.whichPassword();
}