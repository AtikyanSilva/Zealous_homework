#include <iostream>
#include <string>
using namespace std;
class BankAccount{
    private:
    int balance = 0;
    string history = "";
    int sessionLimit = 0;
    int allLimit = 10000;
    public:
    BankAccount(){
        sessionLimit = 400;
    }
    bool isNumber(string numString){
        for(char n : numString){
            if(!isdigit(n)){
                return false;
            }}
        return true;}
    void deposit(string countString){
        int count = stoi(countString);
        if(balance + count >= allLimit){
            cout << "Sorry the limit is over." << endl;
            return;
        }
        balance += count;
        allLimit -= count;
        history += "Deposit " + countString;
    }
    void withdraw(string countString){
        int count = stoi(countString);
        if(sessionLimit - count <= 1){
            cout << "The limit of session is over, please start new session." << endl;
            return;
        }
        if(count <= 0){
            cout << "It's less than 0!" << endl; 
            return;
        }
        if(count > balance){
                cout << "You can't take more than you have!" << endl;
                return;
        }
        history += "Withdraw " + countString;
        balance -= count;
        sessionLimit -= count;
    }
    string showHistory(){
        return history + " Balance " + to_string(balance);
    }
    void updateSession(){
        sessionLimit = 400;
        allLimit = 10000;
    }
    int showBalance(){
        return balance;
    }
};
int main(){
    string action = "";
    string countString;
    cout << "To start a session please enter 'Enter': ";
    getline(cin, action);
    action[0] = toupper(action[0]);
    while(action != "Enter"){
        cout << "To start a session please enter 'Enter': ";
        getline(cin, action);
        action[0] = toupper(action[0]);
    }
    BankAccount user;
    while(true){
        cout << "Please enter the action: ";
        getline(cin, action);
        action[0] = toupper(action[0]);
        while(action != "Balance" and action != "History" and action != "Withdraw" and action != "Deposit" and action != "End" and action != "Exit"){
            cout << "Please enter an existing action: ";
            getline(cin, action);
            action[0] = toupper(action[0]);
        }
        if(action == "End"){
            while(action != "Start" and action != "Exit"){
            cout << "To start a new session please enter 'Start': ";
                getline(cin, action);
                action[0] = toupper(action[0]);
            }
            user.updateSession();
        }
        else if(action == "Exit"){
            break;
        }
        else if(action == "Withdraw"){
            cout << "Please enter the sum  you want to take: ";
            getline(cin, countString);
            while(!user.isNumber(countString)){
                cout << "Please enter a number: ";
                getline(cin, countString);
            }
            user.withdraw(countString);
        }
        else if(action == "Deposit"){
            cout << "Please enter the sum you want to add: ";
            getline(cin, countString);
            while(!user.isNumber(countString)){
                cout << "Please enter a number: ";
                getline(cin, countString);
            }
            user.deposit(countString);
        }
        else if(action == "Balance"){
            cout << user.showBalance();
            cout << endl;
        }
        else if(action == "History"){
            cout << user.showHistory();
            cout << endl;
        }
    }
}