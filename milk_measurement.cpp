#include <bits/stdc++.h>
using namespace std;


int main(){
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int N;
    fin >> N;
    vector<tuple<int, string, int>> records(N);
    int day, change;
    string name;
    for(int i = 0; i < N; ++i){
        fin >> day >> name >> change;
        records[i] = make_tuple(day, name, change);
    }
    sort(records.begin(), records.end());
    // order: Bessie, Elsie, Mildred
    int milk_record[N+1][3];
    milk_record[0][0] = milk_record[0][1] = milk_record[0][2] = 7;

    bool winner[3] = {true, true, true};
    bool tmp[3] = {true, true, true};
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        // cerr << i;
        if(get<1>(records[i])=="Bessie") milk_record[i+1][0] = milk_record[i][0] + get<2>(records[i]);
        else milk_record[i+1][0] = milk_record[i][0];
        if(get<1>(records[i])=="Elsie") milk_record[i+1][1] = milk_record[i][1] + get<2>(records[i]);
        else milk_record[i+1][1] = milk_record[i][1];
        if(get<1>(records[i])=="Mildred") milk_record[i+1][2] = milk_record[i][2] + get<2>(records[i]);
        else milk_record[i+1][2] = milk_record[i][2];

        if(milk_record[i+1][0] >= milk_record[i+1][1] && milk_record[i+1][0] >= milk_record[i+1][2]) tmp[0] = true;
        else tmp[0] = false;
        if(milk_record[i+1][1] >= milk_record[i+1][0] && milk_record[i+1][1] >= milk_record[i+1][2]) tmp[1] = true;
        else tmp[1] = false;
        if(milk_record[i+1][2] >= milk_record[i+1][0] && milk_record[i+1][2] >= milk_record[i+1][1]) tmp[2] = true;
        else tmp[2] = false;
        for(int j = 0; j < 3; ++j){
            // cerr << winner[j] << tmp[j];
            if(winner[j]+tmp[j]==1){
                ++cnt;
                break;
            }
        }
        for(int j = 0; j < 3; ++j) winner[j] = tmp[j];
    }
    fout << cnt;
    
}