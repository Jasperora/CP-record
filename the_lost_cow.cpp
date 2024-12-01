#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y, pos, dist = 0, walk_dist = 1;
    fin >> x >> y;
    pos = x;
    for(int i = 0; i < 20; ++i){
        if(i%2 == 0){
            if(y <= x + walk_dist && y >= x) {
                dist += abs(y - pos);
                fout << dist;
                return 0;
            }
            else {
                dist += abs(x + walk_dist - pos);
                pos = x + walk_dist;
            }
            walk_dist *= 2;
        }else{
            if(y >= x - walk_dist && y <= x){
                dist += abs(y - pos);
                fout << dist;
                return 0;
            }
            else{
                dist += abs(x - walk_dist - pos);
                pos = x - walk_dist;
            }
            walk_dist *= 2;
        }
    }
}