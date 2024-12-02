#include <iostream>
#include <fstream>
using namespace std;


int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int X, Y, M;
    fin >> X >> Y >> M;

    int max = 0;
    int X_max_num = int(M/X);
    int tmp;
    for(int i = 0; i <= X_max_num; ++i){
        tmp = X * i;
        while(tmp + Y <= M){
            tmp += Y;
        }
        if(tmp > max) max = tmp;
    }
    fout << max;

}