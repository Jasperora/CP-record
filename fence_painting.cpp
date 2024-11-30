#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream fin("paint.in");
    ofstream fout("paint.out");

    int a, b, c, d;
    fin >> a >> b >> c >> d;

    int min = (a < c) ? a : c;
    int max = (b > d) ? b : d;

    if(c >= a && d <= b){
        fout << b - a;
    }else if(c <= a && d >= b){
        fout << d - c;
    }else if(c <= a && a <= d && d <= b){
        fout << b - c;
    }else if(a <= c && c <= b && d >= b){
        fout << d - a;
    }else{
        fout << (b - a) + (d - c); 
    }
}