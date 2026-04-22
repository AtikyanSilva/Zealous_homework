#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool isPossible(int first, int second, unordered_map<int, int> index) {
    for (auto i : index) {
        if (i.second == second or abs(i.second - second) == abs(i.first - first)) {
            return false;
        }
    }
    return true;
}
void findAllVersion(int n, int first, unordered_map<int, int> index, vector<vector<string>>& allBoards) {
    if(first == n) {
        vector<string> currentBoard;
        for(int i = 0; i < n; i++) {
            string result = "";
            for(int j = 0; j < n; j++) {
                result += (index[i] == j) ? "Q " : "* ";
            }
            currentBoard.push_back(result);
        }
        allBoards.push_back(currentBoard);
        return; 
    }
    for(int i = 0; i < n; i++) {
        if(isPossible(first, i, index)) {
            index[first] = i; 
            findAllVersion(n, first + 1, index, allBoards);
            index.erase(first);
        }
    }
}

int main() {
    int n;
    cout << "Please enter the N: ";
    cin >> n;
    unordered_map<int, int> index;
    vector<vector<string>> allResults;
    findAllVersion(n, 0, index, allResults);
    if(allResults.empty()){
        cout << "No solutions found." << endl;
    }
    else{
        cout << "Found " << allResults.size() << " version:" << endl;
        for(int i = 0; i < allResults.size(); i++){
            cout << "Board " << i + 1 << endl;
            for(int j = 0; j < allResults[i].size(); j++){
                cout << allResults[i][j] << endl;
            }
        }
    }
    return 0;
}