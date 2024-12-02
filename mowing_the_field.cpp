#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");

    int N;
    fin >> N;
    char direction[N];
    int dist[N];
    for(int i = 0; i < N; ++i){
        fin >> direction[i] >> dist[i];
    }

    int max_t = 2147483647;
    // start at [1000][1000]
    int pos_x = 500, pos_y = 500;
    bool farm_visited[1000][1000] = {false};
    int farm_last_visited_time[1000][1000] = {0};

    farm_visited[500][500] = true;
    int time_cnt = 0, tmp;
    for(int i = 0; i < N; ++i){
        if(direction[i]=='N'){
            for(int j = 1; j <= dist[i]; ++j){
                if(farm_visited[pos_x][pos_y+j]){
                    tmp = time_cnt + 1 - farm_last_visited_time[pos_x][pos_y+j];
                    if(tmp < max_t) max_t = tmp;
                }
                farm_visited[pos_x][pos_y+j] = true;
                farm_last_visited_time[pos_x][pos_y+j] = ++time_cnt;
            }
            pos_y += dist[i];
        }
        else if(direction[i]=='S'){
            for(int j = 1; j <= dist[i]; ++j){
                if(farm_visited[pos_x][pos_y-j]){
                    tmp = time_cnt + 1 - farm_last_visited_time[pos_x][pos_y-j];
                    if(tmp < max_t) max_t = tmp;
                }
                farm_visited[pos_x][pos_y-j] = true;
                farm_last_visited_time[pos_x][pos_y-j] = ++time_cnt;
            }
            pos_y -= dist[i];
        }
        else if(direction[i]=='E'){
            for(int j = 1; j <= dist[i]; ++j){
                if(farm_visited[pos_x+j][pos_y]){
                    tmp = time_cnt + 1 - farm_last_visited_time[pos_x+j][pos_y];
                    if(tmp < max_t) max_t = tmp;
                }
                farm_visited[pos_x+j][pos_y] = true;
                farm_last_visited_time[pos_x+j][pos_y] = ++time_cnt;
            }
            pos_x += dist[i];
        }
        else{// 'W'
            for(int j = 1; j <= dist[i]; ++j){
                if(farm_visited[pos_x-j][pos_y]){
                    tmp = time_cnt + 1 - farm_last_visited_time[pos_x-j][pos_y];
                    if(tmp < max_t) max_t = tmp;
                }
                farm_visited[pos_x-j][pos_y] = true;
                farm_last_visited_time[pos_x-j][pos_y] = ++time_cnt;
            }
            pos_x -= dist[i];
        }
    }
    if(max_t==2147483647) fout << -1;
    else fout << max_t;
    
}