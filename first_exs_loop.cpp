#include <iostream>
using namespace std;
bool isTrue(int nums[], int countOfNums){
    for (int i = 0; i < countOfNums; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < countOfNums - 1; i++) {
        for (int j = i + 1; j < countOfNums; j++){
            if(nums[i] == nums[j]){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int countOfNums;
    cout << "Ներմուծեք տարրերի քանակը։ ";
    cin >> countOfNums;
    int nums[countOfNums];
    cout << "Ներմուծեք տարրերը։ ";
    cout << isTrue(nums, countOfNums);
    return 0;
}