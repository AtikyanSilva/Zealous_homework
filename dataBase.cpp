#include <iostream>
#include <vector> 
struct date{
    int year;
    int month;
    int day;
};
struct info{
    std::string id;
    std::string data;
    date currentDate;
    date lastUpdate;
};
bool whichLatest(info firstBase, info secondBase){
    if(firstBase.currentDate.year != secondBase.currentDate.year)
        return firstBase.currentDate.year > secondBase.currentDate.year;
    if(firstBase.currentDate.month != secondBase.currentDate.month)
        return firstBase.currentDate.month > secondBase.currentDate.month;
    return firstBase.currentDate.day >= secondBase.currentDate.day;
}
bool whichLatestUpdateDate(info firstBase, info secondBase){
    if(firstBase.lastUpdate.year != secondBase.lastUpdate.year)
        return firstBase.lastUpdate.year > secondBase.lastUpdate.year;
    if(firstBase.lastUpdate.month != secondBase.lastUpdate.month)
        return firstBase.lastUpdate.month > secondBase.lastUpdate.month;
    return firstBase.lastUpdate.day >= secondBase.lastUpdate.day;
}
int main()
{
    std::vector<info> firstBase = {
        {"1", "A", {2021, 1, 10}, {2024, 1, 1}},
        {"2", "B", {2022, 3, 2},  {2025, 12, 25}},
        {"3", "C", {2023, 7, 8},  {2026, 2, 15}}
    };

    std::vector<info> secondBase = {
        {"4", "D", {2020, 1, 1}, {2029, 6, 30}},
        {"2", "E", {2025, 9, 9}, {2028, 3, 12}},
        {"6", "F", {2026, 4, 4}, {2017, 11, 11}}
    };
    int i = 0;
    int j = 0;
    int firstBaseSize = firstBase.size();
    while(true){
        if(i == firstBase.size() or j == secondBase.size()){
            break;
    }
        if(whichLatest(firstBase[i], secondBase[j])){
            firstBase.push_back(secondBase[j]);
            i++;
        }
        else if(firstBase[i].id == secondBase[j].id){
            if(whichLatestUpdateDate(firstBase[i], secondBase[j])){
                secondBase[j] = firstBase[i];
        }
        else{
                firstBase[i] = secondBase[j];
        }
        }
            i++;
            j++;
    }
    i = 0;
    j = 0;
    while(true){
        if(i == secondBase.size() or j == firstBaseSize){
            break;
        }
        if(whichLatest(secondBase[i], firstBase[j])){
            secondBase.push_back(firstBase[j]);
            i++;
        }
        else if(firstBase[i].id == firstBase[j].id){
            if(whichLatestUpdateDate(firstBase[j], secondBase[i])){
                secondBase[i] = firstBase[j];
            }
            else{
                firstBase[j] = secondBase[i];
            }
            i++;
        }
        j++;
    }
    for (const auto& item : firstBase) {
    std::cout << item.id << " "
              << item.data << " "
              << item.currentDate.year << "-"
              << item.currentDate.month << "-"
              << item.currentDate.day << " "
              << item.lastUpdate.year << "-"
              << item.lastUpdate.month << "-"
              << item.lastUpdate.day
              << "\n";
}
std::cout << std::endl;
for(const auto& item : secondBase){
    std::cout << item.id << " "
              << item.data << " "
              << item.currentDate.year << "-"
              << item.currentDate.month << "-"
              << item.currentDate.day << " "
              << item.lastUpdate.year << "-"
              << item.lastUpdate.month << "-"
              << item.lastUpdate.day
              << "\n";
}
    return 0;
}
