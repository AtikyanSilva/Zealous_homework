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
string findMax(vector<Cities>& allCities){
    long long maxPopulation = -1;
    string maxCity = "No such a city";
    for(int i = 0; i < allCities.size(); i++){
        if(allCities[i].population > maxPopulation){
            maxPopulation = allCities[i].population;
            maxCity = allCities[i].city;
        }
    }
    return maxCity;
}
string findRandom(vector<Cities>& allCities){
    int maxRange = allCities.size();
    int randomNum = rand() % (maxRange - 0 + 1) + 0;
    string randomCity = allCities[randomNum].city;
    return randomCity;
}
vector<Cities> findAllCity(char lastChar, vector<Cities>& listCities){
    vector<Cities> allCities;
    for(int i = 0; i < listCities.size(); i++){
        if((listCities[i].city)[0] == toupper(lastChar)){
            allCities.push_back(listCities[i]);
        }
    }
    return allCities;
}
bool isContainWithMistake(string city, vector<Cities>& listCities){
    int matchChar = 0;
    int minMatch = 10;
    string moreSimilarCity = "";
    string nextCity = "";
    if(city == "Help"){
        return false;
    }
    for(int i = 0; i < listCities.size(); i++){
        string nextCity = listCities[i].city;
        if((city.length() != nextCity.length() - 1 and city.length() != nextCity.length())){
        continue;}
        matchChar =  nextCity.length() - 2;
        for(int j = 0; j < nextCity.length(); j++){
            if(city.length() == nextCity.length() - 1){
            if(nextCity[j] == city[j] or nextCity[j + 1] == city[j]){
                matchChar--;
            }}
            else{
                if(nextCity[j] == city[j]){
                    matchChar--;
            }
            }
            }
        if(matchChar < minMatch){
            minMatch = matchChar;
            moreSimilarCity = nextCity;
        }
    }
    if(minMatch != 10){
        cout << "Did you mean: " + moreSimilarCity << endl;
        return true;
    }
    return false;
}
bool isContain(string city, vector<Cities>& listCities, bool& isSimilar){
    for(int i = 0; i < listCities.size(); i++){
        if(city == listCities[i].city){
            listCities.erase(listCities.begin() + i);
            return true;
        }
    }
    if(isContainWithMistake(city, listCities)){
        isSimilar = true;
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
    bool theFirstTime = true;
    char lastComputerChar = ' ';
    char firstUserChar = ' ';
    string computerAnswer = "";
    bool help = false;
    bool isSimilar = false;
    while(true){
    while(true){
        help = false;
        isSimilar = false;
        cout << "Please enter the city: ";
        getline(cin, city);
        city[0] = toupper(city[0]);
        if(!theFirstTime){
        firstUserChar = city[0];}
        if(city == "Help"){
            if(theFirstTime){
                string suggestionAnswer = findRandom(data);
                cout << "Maybe " + suggestionAnswer << endl;
                help = true;
            }
            else{
            vector<Cities> allSuggestion =  findAllCity(lastComputerChar, data);
            string suggestionAnswer = findRandom(allSuggestion);
            cout << "Maybe " + suggestionAnswer << endl;
            help = true;}
        }
        if(isContain(city, data, isSimilar) && toupper(firstUserChar) == toupper(lastComputerChar)){ 
            break;
        }
        else{
            if(!help && !isSimilar){
            cout << "Wrong city" << endl;
        }}
    }
    char lastChar = city[city.length() - 1];
    vector<Cities> allCities =  findAllCity(lastChar, data);
    string computerAnswer = findMax(allCities);
    lastComputerChar = computerAnswer[computerAnswer.length() - 1];
    theFirstTime = false;
    help = false;
    cout << computerAnswer << endl; 
}

    return 0;
}