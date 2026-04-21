#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class userInput{
    private:
    stack<string> userType;
    stack<string> userDelete;
    vector<int> lastOperation;
    public:
    void print(){
        stack <string> copyUserType = userType;
        if(copyUserType.empty()){
            cout << "Empty!" << endl;
            return;
        }
        while(!copyUserType.empty()){
            cout << copyUserType.top() << " ";
            copyUserType.pop();
        }
        cout << endl;
    }
    void type(string text){
        userType.push(text);
        lastOperation.push_back(1);
    }
    void delete1(){
    if(!userType.empty()){
        userDelete.push(userType.top());
        userType.pop();
        lastOperation.push_back(0);
    }
}
    void undo(){
        if(lastOperation.size() > 0){
            if(lastOperation.back()){
                userType.pop();
                lastOperation.pop_back();
            }
            else{
                userType.push(userDelete.top());
                userDelete.pop();
            }
        }
        cout << "No opartion for undo." << endl;
    }
};
int main()
{
   userInput user;
   string command = "";
   string line = "";
   while(true){
       cout << "Please enter a command: ";
       cin >> command;
       command[0] = toupper(command[0]);
       while(command != "Type" and command != "Delete" and command != "Print" and command != "Undo" and command != "End"){
           cout << "Please enter valid command: ";
           cin >> command;
       }
       if(command == "Type"){
           cin >> line;
           user.type(line);
       }
       else if(command == "Delete"){
           user.delete1();
       }
       else if(command == "Print"){
           user.print();
       }
       else if(command == "Undo"){
           user.undo();
       }
       else{
           break;
       }
   }
    
    return 0;
}
