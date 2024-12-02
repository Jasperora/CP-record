#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int N;
    fin >> N;
    int a[N+1], cow_ID[N+1], tmp_cow_ID[N+1];
    for(int i = 1; i <= N; ++i) fin >> a[i];
    for(int i = 1; i <= N; ++i) fin >> cow_ID[i];

    for(int i = 0; i < 3; ++i){
        for(int j = 1; j <= N; ++j){
            tmp_cow_ID[j] = cow_ID[a[j]];
        }
        for(int j = 1; j <= N; ++j){
            cow_ID[j] = tmp_cow_ID[j];
        }
    }

    for(int i = 1; i <= N; ++i){
        fout << cow_ID[i] << '\n';
    }
}