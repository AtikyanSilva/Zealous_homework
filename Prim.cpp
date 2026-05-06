#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
struct data{
	std::string point;
	int s;
};
void fillPoints(std::unordered_map<std::string, std::vector<data>> &points){
	std::cout << "If you want to stop input -1" << std::endl;
	std::string from;
	std::string to;
	int s;
	while(true){
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
void findMinPath(std::unordered_map<std::string, std::vector<data>> points){
	std::unordered_map<std::string, int> path;
	std::unordered_map<std::string, std::string> connections;
	auto fst = points.begin();
	std::string start = fst->first;
	path[start] = 1;
	connections[start] = "";
	std::string end = start;
	while(true){
		int minS = 10000;
		std::string minfrom = "";
		std::string minto = "";
		for(auto p : path){
			std::string current = p.first;
			for(int i = 0; i < points[current].size(); i++){
				std::string next = points[current][i].point;
				int s = points[current][i].s;
				if(path.find(next) == path.end() and s < minS){
					minS = s;
					minfrom = current;
					minto = next;
				}
			}
		}
        if(minto == "") break;
		path[minto] = 1;
		connections[minto] = minfrom;
		end = minto;
	}
	std::vector<std::string> result;
	std::string newPoint = end;
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
	std::unordered_map<std::string, std::vector<data>> points;
	fillPoints(points);
	findMinPath(points);
	return 0;
}
