#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

// such method would make p[N] to be unsorted...sorted
int main(){
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int N;
    fin >> N;
    int p[N];
    for(int i = 0; i < N; ++i) fin >> p[i];

    int cnt = 0;
    for(int i = N-1; i >= 1; --i){
        if(!(p[i]>p[i-1])){
            cnt = i;
            break;
        }
    }
    fout << cnt;
}