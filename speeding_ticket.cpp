#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int N, M;
    fin >> N >> M;
    int length[N], speed_limit[N];
    int drive_length[M], speed[M];
    for(int i = 0; i < N; ++i) fin >> length[i] >> speed_limit[i];
    for(int i = 0; i < M; ++i) fin >> drive_length[i] >> speed[i];
    // prefix sum
    for(int i = 1; i < N; ++i) length[i] = length[i] + length[i-1];
    for(int i = 1; i < M; ++i) drive_length[i] = drive_length[i] + drive_length[i-1];

    int max = 0, length_cnt = 0, drive_length_cnt = 0, over_speed;
    for(int i = 0; i < 100; ++i){
        if(i >= length[length_cnt]) ++length_cnt;
        if(i >= drive_length[drive_length_cnt]) ++drive_length_cnt;

        over_speed = speed[drive_length_cnt] - speed_limit[length_cnt];
        if(over_speed > max) max = over_speed;
    }
    fout << max;
}