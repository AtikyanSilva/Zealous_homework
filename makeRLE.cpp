#include <iostream> 
#include <unordered_map>
using namespace std;
string makeRLE(string a){
    unordered_map <char, int> count; 
    // Օգտագործում եմ unordered_map, որպեսզի յուրաքանչյուր սիմվոլի համար պահեմ հանդիպելու քանակը
    string result;
    for(int i = 0; i < a.length(); i++){ // Եթե սիմվոլը գոյություն ունի map-ում ցուցիչը ավելացնում եմ 
        if(count.find(a[i]) != count.end()){ 
            count[a[i]]++;
        }
        else{ // Հակառակ դեպքում, եթե նոր սիմվոլ է
            if (!count.empty()) { // Ստուգում եմ արդյոք նախորդ սիմվոլներ կան map-ում
                auto firstElement = count.begin(); // Եթե այո, ապա մինչև map-ի պարունակությունը ջնջելը, նախորդ տվյալները պետք է պահել
                if(firstElement->second > 1){ // Պահում եմ քանակը, եթե մեծ է 1-ից
                result += to_string(firstElement->second);}
                result += firstElement->first; // Պահում եմ սիմվոլը
            }
            count.clear(); // Մաքրում եմ map-y, որպեսզի կրկնող, բայց իրար չհաջորդող սիմվոլների համար ցուցիչը 0 լինի
            count[a[i]]++; // Եվ առաջին նոր էլէմենտը չկորցնելու համար ցուցիչը ավելացնում եմ 
        }
    }
    if (!count.empty()) { // Վերջում ստուգումը ևս մեկ անգամ եմ անում, վերջին սիմվոլը ևս պահելու համար (քանզի այս գործուղություննեևը ցիկլում կատարվում են միայն նոր էլէմենտ ավելացնելիս)
                auto firstElement = count.begin();
                if(firstElement->second > 1){
                result += to_string(firstElement->second);}
                result += firstElement->first;
            }
    return result;
}
int main()
{
    string a = "aaabcdddaaahygg";
    cout << makeRLE(a);

    return 0;
}