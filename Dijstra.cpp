#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>
struct data{
    std::string point;
    int s;
};
struct nodeInfo{
    int s;                   
    std::string parent;
};
void fillPoints(std::unordered_map<std::string, std::vector<data>> &points){
    std::cout << "If you want to stop input -1" << std::endl;
    std::string from;
    std::string to;
    int s;
    while (true) {
        std::cout << "Please input start: ";
        std::cin >> from;
        if(from == "-1"){
            break;
        }
        std::cout << "Please input end: ";
        std::cin >> to;
        std::cout << "Please input s: ";
        std::cin >> s;
        points[from].push_back({to, s});
    }
}
void findMinPath(std::string from, std::unordered_map<std::string, std::vector<data>> points, std::string to){
    std::unordered_map<std::string, int> path;
    std::unordered_map<std::string, std::string> connections;
    path[from] = 0;
    connections[from] = "";
    for(int i = 0; i < points.size(); i++){
        std::string current = "";
        int min = -1;
        for(auto p : path){
            if(min == -1 or p.second < min){
                min = p.second;
                current = p.first;
            }
        }
        for(auto p : points[current]){
            int newS = path[current] + p.s;
            if(path.find(p.point) == path.end()){
                path[p.point] = newS;
                connections[p.point] = current;
            }
            else if(newS < path[p.point]){
                path[p.point] = newS;
                connections[p.point] = current; 
            }
        }
        path[current] = 10000; 
    }
    std::vector<std::string> result;
    std::string newPoint = to;
    while(newPoint != ""){
        result.push_back(newPoint);
        newPoint = connections[newPoint];
    }
    std::cout << "The min path: ";
    for(int i = result.size() - 1; i >= 0; i--){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    data d;
    std::string from;
    std::string to;
    std::unordered_map<std::string, std::vector<data>> points;
    fillPoints(points);
    std::cout << "Please enter from which city do you wanna find the shortes way: ";
    std::cin >> from;
    std::cout << "Please enter where do you wanna go: ";
    std::cin >> to;
    findMinPath(from, points, to);
    return 0;
}
