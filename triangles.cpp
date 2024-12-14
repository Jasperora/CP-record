#include <iostream>
#include <fstream>
using namespace std;


int compute(int x1, int x2, int x3, int y1, int y2, int y3){
    if(x1==x2 && x1!=x3){
        if(y3==y1) return abs(y2-y1) * abs(x3-x1);
        else if(y3==y2) return abs(y2-y1) * abs(x3-x2);
        else return -1;
    }else if(x2==x3 && x2!=x1){
        if(y1==y2) return abs(y3-y2) * abs(x1-x2);
        else if(y1==y3) return abs(y3-y2) * abs(x1-x3);
        else return -1;
    }else if(x1==x3 && x1!=x2){
        if(y2==y1) return abs(y3-y1) * abs(x2-x1);
        else if(y2==y3) return abs(y3-y1) * abs(x2-x3);
        else return -1;
    }else return -1;
}

int main(){
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int N;
    fin >> N;
    int point[N][2];

    for(int i = 0; i < N; ++i){
        fin >> point[i][0] >> point[i][1];
    }

    int max = 0;
    for(int i = 0; i < N-2; ++i){
        for(int j = i+1; j < N-1; ++j){
            for(int k = j+1; k < N; ++k){
                int tmp = compute(point[i][0], point[j][0], point[k][0], point[i][1], point[j][1], point[k][1]);
                if(tmp > max) max = tmp;
            }
        }
    }
    fout << max;
}