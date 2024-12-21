#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("square.in");
    ofstream fout("square.out");

    //bl: bottom-left, tr: top-right
    int bl1_x, bl1_y, tr1_x, tr1_y, bl2_x, bl2_y, tr2_x, tr2_y;
    fin >> bl1_x >> bl1_y >> tr1_x >> tr1_y >> bl2_x >> bl2_y >> tr2_x >> tr2_y;

    int min_x, min_y, max_x, max_y;
    min_x = min(bl1_x, bl2_x);
    max_x = max(tr1_x, tr2_x);
    min_y = min(bl1_y, bl2_y);
    max_y = max(tr1_y, tr2_y);

    int width = max(max_x-min_x, max_y-min_y);
    fout << width*width;
}