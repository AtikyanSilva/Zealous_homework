#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
void foundPath(std::pair<int,int> connections[4][4], std::pair<int, int> end){
    std::vector<std::pair<int,int>> path;
    while(!(end.first == 0 and end.second == 0)){
        path.push_back(end);
        end = connections[end.first][end.second];
    }
    path.push_back({0,0});
    reverse(path.begin(), path.end());
    std::cout << "The shortest path cordinate: ";
    for(int i = 0; i < path.size(); i++){
        std::cout << path[i].first << ", " << path[i].second;
        std::cout << std::endl;
    }
}
void findShortestPath(char labirinth[4][4]){
    std::pair<int,int> connections[4][4];
    bool been[4][4] = {false};
    std::queue<std::pair<int,int>> q;
    std::pair<int, int> end;
    q.push({0,0});
    been[0][0] = true;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;
            if(labirinth[x][y] == 'F'){
                end = {x, y};
                foundPath(connections, end);
                return;
            }
            for(int i = 0; i < 4; i++){
                if(x + dx[i] >= 0 and y + dy[i] >= 0 and x + dx[i] <= 3 and y + dy[i] <= 3 and labirinth[x + dx[i]][y + dy[i]] != '#' and !been[x + dx[i]][y + dy[i]]){
                    q.push({x + dx[i], y + dy[i]});
                    been[x + dx[i]][y + dy[i]] = true;
                    connections[x + dx[i]][y + dy[i]] = {x, y};
                }
            }
        }
        
    }
}
int main()
{
    char labirinth[4][4] = {
        {'S', '.', '#', '.'},
        {'.', '.', '#', '.'},
        {'#', '.', '.', '.'},
        {'.', '#', '.', 'F'}
    };
    findShortestPath(labirinth);
    return 0;
}
