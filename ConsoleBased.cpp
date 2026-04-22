#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class userInput{
    private: 
    stack<string> userType;
    stack<string> userDelete;
    vector<int> lastOperation;
    stack<int> deleteCount;
    int output = 0;
    public:
    void print(){
        stack<string> copyUserType = userType;
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
        output += text.length();
    }
    void undo(){
        if(lastOperation.size() > 0){
            if(lastOperation.back()){
                if(!userType.empty()){
                    output -= userType.top().length();
                    userType.pop();
                }
                lastOperation.pop_back();
                return;
            }
            else{
                if(!deleteCount.empty()){
                    int parts = deleteCount.top();
                    deleteCount.pop();
                    while(parts--){
                        if(!userDelete.empty()){
                            userType.push(userDelete.top());
                            userDelete.pop();
                        }
                    }
                }
                lastOperation.pop_back();
                return;
            }
        }
        cout << "No opartion for undo." << endl;
    }
    void delete1(int count){
        if(output < count or count < 0){
            cout << "Invalid number" << endl;
            return;
        }
        output -= count;
        int deletedParts = 0;
        while(count != 0 and !userType.empty()){
            string top = userType.top();
            if(top.length() <= count){
                userDelete.push(top);
                userType.pop();
                count -= top.length();
                deletedParts++;
            }
            else{
                string newTop = "";
                string deletePart = "";
                for(int i = 0; i < top.length() - count; i++){
                    newTop += top[i];
                }
                for(int i = top.length() - count; i < top.length(); i++){
                    deletePart += top[i];
                }
                userType.pop();
                userType.push(newTop);
                userDelete.push(deletePart);
                deletedParts++;
                count = 0;
            }
    }
        deleteCount.push(deletedParts);
        lastOperation.push_back(0);
    }
};

int main(){
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
            int num;
            cin >> num;
            user.delete1(num);
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
