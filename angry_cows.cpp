#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// ******************
// fail one test case
// ******************

int N;
bool notfinished(int* locations, int lower_range, int upper_range, bool* exploded){
    for(int i = 0; i < N; ++i){
        if(locations[i] >= lower_range && locations[i] <= upper_range && exploded[i] == false){
            return true;
        }
    }
    return false;
}

int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    fin >> N;
    
    int locations[N];
    for(int i = 0; i < N; ++i) fin >> locations[i];

    sort(locations, locations+N);
    int sol = -1;
    for(int i = 0; i < N; ++i){
        int cnt = 1;
        int lower_range = locations[i]-cnt, upper_range = locations[i]+cnt;
        bool exploded[N];
        fill(exploded, exploded+N, false);
        exploded[i] = true;
        while(notfinished(locations, lower_range, upper_range, exploded)){
            int min = 1001;
            int max = -1;
            for(int j = 0; j < N; ++j){
                if(locations[j] >= lower_range && locations[j] <= upper_range){
                    exploded[j] = true;
                    if(j < min) min = j;
                    if(j > max) max = j;
                }
            }
            if(min != 1001) lower_range = locations[min] - cnt;
            if(max != -1) upper_range = locations[max] + cnt;
            ++cnt;
        }
        int sum = 0;
        for(int j = 0; j < N; ++j) sum += exploded[j];
        if(sum > sol) sol = sum;
    }
    fout << sol;
}