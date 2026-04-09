#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int maxOfNums(int first, int second) {
	if(first >= second) {
		return first;
	}
	return second;
}
int minOfNums(int first, int second) {
	if(first >= second) {
		return second;
	}
	return first;
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
	cout << "Please enter intervals: ";
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		intervals.push_back({start, end});
	}
	cout << "Please enter new_interval: ";
	cin >> start >> end;
	int first = 0;
	int last = 0;
	int i = 0;
	while(i < n and intervals[i][1] < start) {
		intervalsCorrect.push_back({intervals[i][0], intervals[i][1]});
		i++;
	}
	while(i < n and intervals[i][0] <= end) {
		start = minOfNums(start, intervals[i][0]);
		end = maxOfNums(end, intervals[i][1]);
		i++;
	}
	intervalsCorrect.push_back({start, end});
	while(i < n) {
		intervalsCorrect.push_back({intervals[i][0], intervals[i][1]});
		i++;
	}
for (int i = 0; i < intervalsCorrect.size(); i++) {
	cout << "[" << intervalsCorrect[i][0] << ", " << intervalsCorrect[i][1] << "] ";
}
return 0;
}
