#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int makeNum(string numString){
    int num = 0;
    if(numString.length() == 1){
        return numString[0] - '0';
    }
    num += (numString[0] - '0') * 10;
    num += numString[1] - '0';
    return num;
}
class workItems{
    private:
    unordered_map<string, vector<int>> items;
    vector<string> sortedItems;
    public:
    void add(string item, int time1){
        items[item].push_back(time1);
        sortedItems.push_back(item);
        sortedItems.push_back(to_string(time1));
    }
    vector<string> sortAll(){
        for(int i = 0; i < sortedItems.size(); i += 2){
            for(int j = 0; j < sortedItems.size(); j += 2){
                if(sortedItems[i] < sortedItems[j]){
                    string temp = sortedItems[i];
                    sortedItems[i] = sortedItems[j];
                    sortedItems[j] = temp;
                    temp = sortedItems[i + 1];
                    sortedItems[i + 1] = sortedItems[j + 1];
                    sortedItems[j + 1] = temp;
                }
            }
        }
        return sortedItems;
    }
    vector<string> queryByTime(){
        for(int i = 0; i < sortedItems.size(); i += 2){
            for(int j = 0; j < sortedItems.size(); j += 2){
                if(makeNum(sortedItems[i + 1]) < makeNum(sortedItems[j + 1])){
                    string temp = sortedItems[i];
                    sortedItems[i] = sortedItems[j];
                    sortedItems[j] = temp;
                    temp = sortedItems[i + 1];
                    sortedItems[i + 1] = sortedItems[j + 1];
                    sortedItems[j + 1] = temp;
                }
        }
    }
    return sortedItems;
}
    void search(string searchWord){
        if(items.find(searchWord) != items.end()){
            cout << searchWord << ": ";
            for(int i = 0; i < (items[searchWord]).size(); i++){
                cout << (items[searchWord])[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "No such a item: " << endl;
        }

    }
    };
int main(){
    workItems item;
    string command;
    cout << "Please enter the command: ";
    cin >> command;
    string word;
    int count;
    int time1;
    vector<string> sortByTime;
    vector<string> sort;
    command[0] = toupper(command[0]);
    while(command != "Add" and command != "Search" and command != "Sort" and command != "Query" and command != "End"){
        cout << "Invalid input, please enter the command again: ";
        cin >> command;
        command[0] = toupper(command[0]);
    }
    while(command != "End"){
        if(command == "Add"){
            cout << "Please enter the item and the time: ";
            cin >> word;
            cin >> count;
            while(count > 24 and count < 0){
                cout << "Invalid input, please enter num from 0-24 range: ";
                cin >> count;
            }
            item.add(word, count);
        }
        else if(command == "Search"){
            cout << "Please enter name of item you want to search: ";
            cin >> word;
            item.search(word);
        }
        else if(command == "Sort"){
            sort = item.sortAll();
            for(int i = 0; i < sort.size(); i += 2){
                cout << sort[i] << " " << sort[i + 1] << endl;
        }
        }
        else if(command == "Query"){
            cin >> time1;
            while(time1 > 24 and time1 < 0){
                cout << "Invalid input, please enter num from 0-24 range: ";
                cin >> time1;
            }
            sortByTime = item.queryByTime();
            for(int i = 0; i < sortByTime.size(); i += 2){
                if(makeNum(sortByTime[i + 1]) <= time1){
                    cout << sortByTime[i] << " " << sortByTime[i + 1] << endl;
             }}}
             cout << "Please enter the command: ";
             cin >> command;
             command[0] = toupper(command[0]);
             while(command != "Add" and command != "Search" and command != "Sort" and command != "Query" and command != "End"){
                cout << "Invalid input, please enter the command again: ";
                cin >> command;
                command[0] = toupper(command[0]);}
    }
    return 0;
}