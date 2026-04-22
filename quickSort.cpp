#include <iostream>
#include <vector>
using namespace std;
int findNumber(vector<int> sortedArray){
    int arraySize = sortedArray.size();
    if(arraySize == 1){
        return sortedArray[0];
    }
    int isMore;
    cout << "Is number more or equel to:  " + to_string(sortedArray[arraySize / 2]) << endl;
    cout << "Please enter 1 / 0 (yes, no): ";
    cin >> isMore;
    while(isMore != 0 and isMore != 1){
        cout << "You can enter 1 / 0 (yes, no): ";
        cin >> isMore;
    }
    if(isMore){
        vector<int> newArray(sortedArray.begin() + arraySize / 2, sortedArray.end());
        return findNumber(newArray);
    }
    else{
        vector<int> newArray(sortedArray.begin(), sortedArray.begin() + arraySize / 2);
        return findNumber(newArray);
    }
}
int main()
{
    int result = findNumber({1, 2, 4, 10, 15, 17, 19, 20, 21, 24, 26, 30, 45, 54, 58, 59});
    cout << "The result is: " << result;

    return 0;
}