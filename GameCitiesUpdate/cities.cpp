#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct Cities {
    int id;
    string city;
    double lat;
    double lng;
    string country;
    string iso2;
    string iso3;
    long long population;
};
vector<Cities> returnQuery(string frst, string op, string rst, const vector<Cities>& allCities){
    vector<Cities> answer;
    for(int i = 0; i < allCities.size(); i++){
        if(frst == "country"){
            if(allCities[i].country == rst){
                answer.push_back(allCities[i]);
        }}
        else if(frst == "city"){
            long long cityPopulation = 0;
                for (const auto& c : allCities) {
                    if (c.city == rst) {
                        cityPopulation = c.population;
                        break;
                }
            }
            if(op == "=="){
                if(allCities[i].population == cityPopulation){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">="){
                if(allCities[i].population >= cityPopulation){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<="){
                if(allCities[i].population <= cityPopulation){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">"){
                if(allCities[i].population > cityPopulation){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<"){
                if(allCities[i].population < cityPopulation){
                    answer.push_back(allCities[i]);
                }
            }
        }
        else if(frst == "lat"){
            if(op == "=="){
                if(allCities[i].lat == stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">="){
                if(allCities[i].lat >= stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<="){
                if(allCities[i].lat <= stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">"){
                if(allCities[i].lat > stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<"){
                if(allCities[i].lat < stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
        }
        else if(frst == "lng"){
            if(op == "=="){
                if(allCities[i].lng == stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">="){
                if(allCities[i].lng >= stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<="){
                if(allCities[i].lng <= stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">"){
                if(allCities[i].lng > stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<"){
                if(allCities[i].lng < stod(rst)){
                    answer.push_back(allCities[i]);
                }
            }
        }
        else if(frst == "population"){
            if(op == "=="){
                if(allCities[i].population == stoll(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">="){
                if(allCities[i].population >= stoll(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<="){
                if(allCities[i].population <= stoll(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == ">"){
                if(allCities[i].population > stoll(rst)){
                    answer.push_back(allCities[i]);
                }
            }
            else if(op == "<"){
                if(allCities[i].population < stoll(rst)){
                    answer.push_back(allCities[i]);
                }
            }
        } 
    }
    return answer;
}
int isValid(string frst, string op, string rst, const vector<Cities> allCities){
    vector<string> posibleFields = {"city", "lat", "lng", "country", "population"};
    bool isPosible = false;
    for(int i = 0; i < 5; i++){
        if(frst == posibleFields[i]){
            isPosible = true;
            break;
        }
    }
    bool isPosibleCity = false;
    if(isPosible){
        if(frst == "country"){
            if(op != "==") return false;
            for(int i = 0; i < allCities.size(); i++){
                if(allCities[i].country == rst){
                    isPosibleCity = true;
                    break;
                }
            }
            if(!isPosibleCity) return false;
        }
        else if(frst == "city"){
            for(int i = 0; i < allCities.size(); i++){
                if(allCities[i].city == rst){
                    isPosibleCity = true;
                    break;
                }
            }
            if(!isPosibleCity) return false;
        }
        else{
            try {
                stod(rst);
                return true;
            }
            catch (...){
                return false;
            }
        }
        return true;
    }
    return false;
}
bool isContain(string city, vector<Cities>& listCities){
    for(int i = 0; i < listCities.size(); i++){
        if(city == listCities[i].city){
            listCities.erase(listCities.begin() + i);
            return true;
        }
    }
    return false;
}
int main() { 
    ifstream file("worldcities.csv");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    vector<Cities> data;
    string line;

    getline(file, line); 

    while (getline(file, line)) {
        stringstream part(line);
        string temp;
        Cities newCity;

        try {
            getline(part, temp, ','); newCity.id = stoi(temp);
            getline(part, newCity.city, ',');
            getline(part, temp, ','); newCity.lat = stod(temp);
            getline(part, temp, ','); newCity.lng = stod(temp);
            getline(part, newCity.country, ',');
            getline(part, newCity.iso2, ',');
            getline(part, newCity.iso3, ',');
            getline(part, temp, ','); newCity.population = (temp.empty() || temp == "\r") ? 0 : stoll(temp);

            data.push_back(newCity);
        } catch (...) {
            continue; 
        }
    }
    file.close();
    string city;
    while(true){
    cout << "Please enter the city: ";
    getline(cin, city);
    if(isContain){
        break;
    }
}
    return 0;
}