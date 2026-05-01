#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
bool isDigit(std::string num){
    if(num.empty()) return false;
    for(unsigned char n : num){
        if(!isdigit(n)) return false;
    }
    return true;
}
void fill(std::vector<std::vector<int>>& coordinateOfFiilCells, bool& wrong){
    while(true){
        int x;
        std::string num;
        std::cout << "Please enter the x: ";
        getline(std::cin, num);
        if(isDigit(num)){
            x = stoi(num);
        }
        else{
            if(!num.empty()){
                num[0] = toupper(num[0]);
                if(num == "End"){
                    return;
                }
                else{
                    std::cout << "Invalid input!";
                    wrong = true;
                    return;
                }
            }
            wrong = true;
            std::cout << "Invalid input!";
            return;
        }
        std::cout << "Please enter the y: ";
        getline(std::cin, num);
        if(isDigit(num)){
            int y = stoi(num);
            coordinateOfFiilCells.push_back({x, y});
        }
        else{
            if(!num.empty()){
                num[0] = toupper(num[0]);
                if(num == "End"){
                    return;
                }
                else{
                    std::cout << "Invalid input!";
                    wrong = true;
                    return;
                }
            }
            wrong = true;
            std::cout << "Invalid input!";
            return;
        }
}}
void draw(std::unordered_map<std::string, int>& allFillCells){
    int minX = 10000, maxX = -10000;
    int minY = 10000, maxY = -10000;
    for(auto cordinate : allFillCells){
        std::string key = cordinate.first;
        int sep = key.find(',');
        int x = std::stoi(key.substr(0, sep));
        int y = std::stoi(key.substr(sep + 1));
        if(x < minX){
            minX = x;
        }
        if(x > maxX){
            maxX = x;
        }
        if(y < minY){
            minY = y;
        }
        if(y > maxY){
            maxY = y;
        }
    }
    minX--;
    maxX++;
    minY--;
    maxY++;
    for(int y = minY; y <= maxY; y++){
        for(int x = minX; x <= maxX; x++){
            std::string key = std::to_string(x) + "," + std::to_string(y);
                if(allFillCells.find(key) != allFillCells.end()){
                    std::cout << "# ";
                }
                else{
                    std::cout << "- ";
                }
            }
            std::cout << std::endl;
        }
}
void nextStep(std::unordered_map<std::string, int>& allFillCells){ 
    while(true){
        std::cout << "Please enter 'Enter' for next step: "; 
        std::string next;
        getline(std::cin, next);
        std::unordered_map<std::string, int> neighborCount;
        for(auto [key, value] : allFillCells){
            int separator = key.find(',');
            int x = std::stoi(key.substr(0, separator));
            int y = std::stoi(key.substr(separator + 1));
            std::vector<std::vector<int>> cordinateNeighbors = {
                {x+1, y}, {x-1, y}, {x, y+1}, {x, y-1},
                {x+1, y+1}, {x-1, y+1}, {x+1, y-1}, {x-1, y-1}
            };
            for(auto neighbors : cordinateNeighbors){
                int x1 = neighbors[0];
                int y1 = neighbors[1];
                std::string stringAsKey = std::to_string(x1) + "," + std::to_string(y1);
                neighborCount[stringAsKey]++;
            }
        }
        for(auto it = allFillCells.begin(); it != allFillCells.end();){ // AI helped me with this part about iterators because I couldn't make changes during a standard loop I knew
            std::string key = it->first;
            int count = neighborCount[key];
            if(count != 2 and count != 3){
                it = allFillCells.erase(it);
            }
            else{
                ++it;
            }
        }
        for(auto [key, count] : neighborCount){
            if(allFillCells.find(key) == allFillCells.end()){
                if(count == 3){
                    allFillCells[key] = 0;
                }
            }
        }
        if(allFillCells.empty()){
        std::cout << "Empty!" << std::endl;
        return;}
        draw(allFillCells);
    }
}
int main()
{
    std::cout << "Please enter the cordinate of the filled cells: "  << std::endl;
    std::cout << "(If you want to stop inputing, enter the word 'End')" << std::endl;
    std::vector<std::vector<int>> coordinateOfFiilCells;
    bool wrong = false;
    fill(coordinateOfFiilCells, wrong);
    std::unordered_map<std::string, int> allFillCells;
    for(auto coordinate : coordinateOfFiilCells){
        std::string key = std::to_string(coordinate[0]) + "," + std::to_string(coordinate[1]);
        allFillCells[key] = 0;
    }
    if(!wrong){
        nextStep(allFillCells);
        
    };
    return 0;
}
