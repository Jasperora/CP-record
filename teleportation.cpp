#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    int a, b, x, y;
    fin >> a >> b >> x >> y;


    int direct = abs(b-a);
    int near = (abs(x-a)<=abs(y-a)) ? x : y;
    int far = x + y - near;

    int teleportation = abs(near-a) + abs(far-b);
    if(direct < teleportation) fout << direct;
    else fout << teleportation;
}