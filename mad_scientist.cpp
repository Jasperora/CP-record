#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int N;
    fin >> N;
    char A[N], B[N];
    for(int i = 0; i < N; ++i){
        fin >> A[i];
    }
    for(int i = 0; i < N; ++i){
        fin >> B[i];
    }

    bool same = true;
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        if(B[i] != A[i] && same == true){
            same = false;
        }
        if(B[i] == A[i] && same == false){
            same = true;
            ++cnt;
        }
    }
    fout << cnt;
}