#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool mid(int a, int b, int c){
    if((a < b && b < c) || (c < b && b < a)) return true;
    else return false;
}

int main(){
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    char c;
    vector<vector<char> > farm;
    for(int i = 0; i < 10; ++i){
        vector<char> v;
        for(int j = 0; j < 10; ++j){
            fin >> c;
            v.push_back(c);
        }
        farm.push_back(v);
    }

    int B_x, B_y, R_x, R_y, L_x, L_y;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if (farm[i][j] == 'B'){
                B_x = i;
                B_y = j;
            }
            if (farm[i][j] == 'R'){
                R_x = i;
                R_y = j;
            }
            if (farm[i][j] == 'L'){
                L_x = i;
                L_y = j;
            }
        }
    }

    if((B_x==R_x && B_x==L_x && mid(B_y, R_y, L_y)) || (B_y==R_y && B_y==L_y && mid(B_x, R_x, L_x)))
        fout << abs(B_x-L_x) + abs(B_y-L_y) + 1;
    else fout << abs(B_x-L_x) + abs(B_y-L_y) - 1;
}