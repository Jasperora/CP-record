#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");

    int N;
    fin >> N;
    string tag[N];
    int lower[N], upper[N];

    for(int i = 0; i < N; ++i) fin >> tag[i] >> lower[i] >> upper[i];

    int a = 0, b = 1e6+1;
    for(int i = N-1; i >= 0; --i){
        if(tag[i] == "on"){
            a = max(0, a-upper[i]);
            b = max(0, b-lower[i]);
        }
        else if(tag[i] == "off"){
            a += lower[i];
            b += upper[i];
        }
        else{
            a = max(a, lower[i]);
            b = min(b, upper[i]);
        }
    }
    fout << a << ' ' << b << '\n';

    a = 0;
    b = 1e6+1;
    for(int i = 0; i < N; ++i){
        if(tag[i] == "on"){
            a += lower[i];
            b += upper[i];
        }
        else if(tag[i] == "off"){
            a = max(0, a-upper[i]);
            b = max(0, b-lower[i]);
        }
        else{ // none
        cout << 'a' << '\n';
            a = max(a, lower[i]);
            b = min(b, upper[i]);
            cout << b << '\n';
        }
    }
    fout << a << ' ' << b;
}