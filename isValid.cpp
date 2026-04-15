#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string line;
    cout << "Please input the line: ";
    cin >> line;
    stack<char> a;
    for (int i = 0; i < line.length(); i++) {
        if(line[i] == '('){
            a.push(')');
        }
        else if(line[i] == '['){
            a.push(']');
        }
        else if(line[i] == '{'){
            a.push('}');
        }
        else if (line[i] == ')' || line[i] == ']' || line[i] == '}') {
            if (a.empty() || a.top() != line[i]) {
                cout << '0';
                return 0;
            }
            a.pop();
        }
    }
    cout << a.empty();
    return 0;
}