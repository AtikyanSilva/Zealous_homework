#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int maxOfNums(int first, int second){
    if(first >= second){
        return first;
    }
    return second;
}
int main()
{
    int n;
    cout << "Please enter the num of intervals: ";
    cin >> n;
    int start;
    int end;
    vector<vector<int>> intervals;
    vector<vector<int>> intervalsCorrect;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        intervals.push_back({start, end});
    }
    sort(intervals.begin(), intervals.end());
    int first = 0;
    int last = intervals[0][1];
    for (int i = 0; i < n; i++) {
        if(i + 1 < n and intervals[i + 1][0] <= last){
            last = maxOfNums(intervals[i + 1][1], last);
        }
        else{
            intervalsCorrect.push_back({intervals[first][0], last});
            if(i + 1 < n){
                first = i + 1;
                last = intervals[i + 1][1];
            }
        }
    }
    for (int i = 0; i < intervalsCorrect.size(); i++) {
    cout << "[" << intervalsCorrect[i][0] << ", " << intervalsCorrect[i][1] << "] ";
}
    return 0;
}
