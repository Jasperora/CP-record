#include <iostream>
#include <fstream>
using namespace std;

int max(int a, int b, int c){
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int N;
    fin >> N;
    int a[N], b[N], g[N];
    for(int i = 0; i < N; ++i) fin >> a[i] >> b[i] >> g[i];

    int score[3] = {0, 0, 0};
    for(int i = 0; i < 3; ++i){
        int ans = i + 1;
        for(int j = 0; j < N; ++j){
            if(a[j]==ans) ans = b[j];
            else if(b[j]==ans) ans = a[j];
            if(g[j]==ans) ++score[i];
        }
    }
    fout << max(score[0], score[1], score[2]);
}