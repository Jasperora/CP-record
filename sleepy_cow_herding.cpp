#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    int locations[3];
    fin >> locations[0] >> locations[1] >> locations[2];
    int minimum, maximum;

    sort(locations, locations+3);
    
    if(locations[1]==locations[0]+1 && locations[2]==locations[1]+1) minimum = 0;
    else if(locations[1]==locations[0]+2 || locations[2]==locations[1]+2) minimum = 1;
    else minimum = 2;

    maximum = max(locations[1]-locations[0], locations[2]-locations[1]) - 1;
    fout << minimum << '\n' << maximum;
}