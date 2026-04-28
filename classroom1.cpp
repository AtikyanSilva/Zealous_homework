#include <iostream>
#include <vector>
#include <string>
void road(int step, int len, std::vector<std::vector<std::string>>& chess, std::vector<int> cordinate){
    if(cordinate[0] + 2 < len and cordinate[1] + 1 < len and chess[cordinate[0] + 2][cordinate[1] + 1] == "-"){
        cordinate[0] += 2;
        cordinate[1] += 1;
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] + 2 < len and cordinate[1] - 1 >= 0 and chess[cordinate[0] + 2][cordinate[1] - 1] == "-"){
        cordinate[0] += 2;
        cordinate[1] -= 1;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] - 2 >= 0 and cordinate[1] + 1 < len and chess[cordinate[0] - 2][cordinate[1] + 1] == "-"){
        cordinate[0] -= 2;
        cordinate[1] += 1;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] - 2 >= 0 and cordinate[1] - 1 >= 0 and chess[cordinate[0] - 2][cordinate[1] - 1] == "-"){
        cordinate[0] -= 2;
        cordinate[1] -= 1;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] - 1 >= 0 and cordinate[1] - 2 >= 0 and chess[cordinate[0] - 1][cordinate[1] - 2] == "-"){
        cordinate[0] -= 1;
        cordinate[1] -= 2;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] + 1 < len and cordinate[1] + 2 < len and chess[cordinate[0] + 1][cordinate[1] + 2] == "-"){
        cordinate[0] += 1;
        cordinate[1] += 2;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] + 1 < len and cordinate[1] - 2 >= 0 and chess[cordinate[0] + 1][cordinate[1] - 2] == "-"){
        cordinate[0] += 1;
        cordinate[1] -= 2;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    if(cordinate[0] - 1 >= 0 and cordinate[1] + 2 < len and chess[cordinate[0] - 1][cordinate[1] + 2] == "-"){
        cordinate[0] -= 1;
        cordinate[1] += 2;
        chess[cordinate[0]][cordinate[1]] = '+';
        chess[cordinate[0]][cordinate[1]] = std::to_string(step);
        step++;
        road(step, len, chess, cordinate);
    }
    return;
    
}
int main(){
    std::cout << "Please enter the size: ";
    int len;
    std::cin >> len;
    if(len <= 4){
        std::cout << "No such a road." << std::endl;
        return 0;
    }
    std::vector<std::vector<std::string>> chess(len, std::vector<std::string>(len));
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            chess[i][j] = '-';
        }
    }
    std::vector<int> cordinate = {0, 0};
    chess[0][0] = "0"; 
    road(1, len, chess, cordinate);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            std::cout << chess[i][j] << " ";
        }
        std::cout << "\n";
    }
}
