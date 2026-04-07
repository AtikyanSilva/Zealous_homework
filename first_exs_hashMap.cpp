#include <iostream>
#include <unordered_map>
using namespace std;
bool isTrue(auto nums){
    for (auto el : nums) {
        if(el.second > 1){
            return true;
        }
    }
    return false;
}
int main()
{
    int countOfNums;
    cout << "Ներմուծեք տարրերի քանակը։ ";
    cin >> countOfNums;
    unordered_map<int, int> nums;
    cout << "Ներմուծեք տարրերը։ ";
    for (int i = 0; i < countOfNums; i++) {
        int el;
        cin >> el;
        nums[el]++;
    }
    cout << isTrue(nums);
    return 0;
}