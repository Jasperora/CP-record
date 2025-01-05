#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<string, pair<string, int> > year;
    map<string, int> chinese_zodiac;
    string animals[12] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
    for(int i = 0; i < 12; ++i) chinese_zodiac[animals[i]] = i+1;
    pair<string, int> p("Ox", 2);
    year["Bessie"] = p;
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        string name1, prev_next, animal, name2, trash;
        cin >> name1 >> trash >> trash >> prev_next >> animal >> trash >> trash >> name2;
        if(prev_next=="previous"){
            year[name1].first = animal;
            if(animal==year[name2].first) year[name1].second = year[name2].second - 12;
            else if(chinese_zodiac[animal]<chinese_zodiac[year[name2].first])
                year[name1].second = year[name2].second - chinese_zodiac[year[name2].first] + chinese_zodiac[animal];
            else year[name1].second = year[name2].second - chinese_zodiac[year[name2].first] - 12 + chinese_zodiac[animal];
        }else{
            year[name1].first = animal;
            if(animal==year[name2].first) year[name1].second = year[name2].second + 12;
            else if(chinese_zodiac[animal]<chinese_zodiac[year[name2].first])
                year[name1].second = year[name2].second - chinese_zodiac[year[name2].first] + 12 + chinese_zodiac[animal];
            else year[name1].second = year[name2].second - chinese_zodiac[year[name2].first] + chinese_zodiac[animal];
        }
    }
    // for(auto& y : year) cout << y.first << ' ' << y.second.second << '\n';
    cout << abs(year["Bessie"].second-year["Elsie"].second);
}