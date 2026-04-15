#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Ներմուծեք թվերի քանանկը։ ";
    cin >> n;
    int nums[n];
    int count = 0;
    int k;
    cout << "Ներմուծեք թվերը։ ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Ներմուծեք k թիվը։ ";
    cin >> k;
    int sum = nums[0];
    int first = 0;
    for (int i = 1; i < n; i++) {
        if(sum == k){
            count++;
            sum -= nums[first];
            first = i - 1;
        }
        else if(sum > k){
            sum -= nums[first];
            first += 1;
            if(sum == k){
                count++;
            }
        }
        sum += nums[i];
        
    }
    if(sum == k){
            count++;}
    cout << count;
    return 0;
}