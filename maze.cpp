#include <iostream>
using namespace std;
void move(int beenThere[12][12], char arr[12][12], char& d, int& i, int& j){
    string enter;
    getline(cin, enter);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    beenThere[i][j]++;
    if(d == '-'){ //top 
        arr[i + 1][j] = 'o';
        arr[i][j] = ' ';
        i += 1;
    }
    else if(d == '*'){ // down
        arr[i - 1][j] = 'o';
        arr[i][j] = ' ';
        i -= 1;
    }
    else if(d == '>'){
        arr[i][j + 1] = 'o';
        arr[i][j] = ' ';
        j += 1;
    }
    else if(d == '<'){
        arr[i][j - 1] = 'o';
        arr[i][j] = ' ';
        j -= 1;
    }
    if(i == 0 or i == 11 or j == 0 or j == 11){
        cout << endl;
        cout << "You find the exit!" << endl;
        return;
    }
    if(arr[i + 1][j] == ' ' and beenThere[i + 1][j] < 2 and d != '*'){
        d = '-';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i][j + 1] == ' ' and beenThere[i][j + 1] < 2 and d != '<'){
        d = '>';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i - 1][j] == ' ' and beenThere[i - 1][j] < 2 and d != '-'){
        d = '*';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i][j - 1] == ' ' and beenThere[i][j - 1] < 2 and d != '>'){
        d = '<';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i + 1][j] == ' ' and beenThere[i + 1][j] < 2){
        d = '-';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i][j + 1] == ' ' and beenThere[i][j + 1] < 2){
        d = '>';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i - 1][j] == ' ' and beenThere[i - 1][j] < 2){
        d = '*';
        move(beenThere, arr, d, i, j);
        return;
    }
    if(arr[i][j - 1] == ' ' and beenThere[i][j - 1] < 2){
        d = '<';
        move(beenThere, arr, d, i, j);
        return;
    }
    else{
        cout << endl;
        cout << "There is no exit! " << endl;
    }
    
}
int main()
{
    int i;
    int j;
    char direction = '>';
    i = 2;
    j = 0;
    cout << "\nPress ENTER to see the object's next steps\n";
    char arr[12][12] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        'o', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ',
        '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#',
        '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
    int beenThere[12][12] = {};
    move(beenThere, arr, direction, i, j);

    return 0;
}

