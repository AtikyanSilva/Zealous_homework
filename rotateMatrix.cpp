#include <iostream>
using namespace std;
int countOfStep(int size_m){
    int result = 0;
    result += size_m - 1;
    if(result < 3){
        return result;
    }
    if(size_m == 3){
        return result;
    }
    return result + countOfStep(size_m - 2);
}
int main()
{
    int n;
    cout << "Please enter the n: ";
    cin >> n;
    int matrix[n][n];
    int countOfStep1 = countOfStep(n);
    int start = 0;
    int end = n - 1;  
    cout << "Please enter elements for matrix: ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        cin >> matrix[i][j];
    }}
    int current = 0;
    for(int i = 0; i < countOfStep1; i++){
        for(int j = start; j < end; j++){
            int t = matrix[start][j];
            matrix[start][j] = matrix[end - (j - start)][start];
            matrix[end - (j - start)][start] = matrix[end][end - (j - start)];
            matrix[end][end - (j - start)] = matrix[j][end];
            matrix[j][end] = t;
        
        }
        start++;
        end--;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        cout << matrix[i][j] << " "; 
    }
        cout << endl;
    }
    return 0;
}