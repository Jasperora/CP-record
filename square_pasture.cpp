#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    //bl: bottom-left, tr: top-right
    // 2 cover 1
    int bl1_x, bl1_y, tr1_x, tr1_y, bl2_x, bl2_y, tr2_x, tr2_y;
    fin >> bl1_x >> bl1_y >> tr1_x >> tr1_y >> bl2_x >> bl2_y >> tr2_x >> tr2_y;

    int first_area = (tr1_y-bl1_y)*(tr1_x-bl1_x);

    if(bl2_x <= bl1_x && tr2_x >= tr1_x){ // might completely cover some y
        if(bl2_y <= bl1_y && tr2_y >= tr1_y) fout << 0;
        else if(bl2_y >= bl1_y && tr2_y <= tr1_y) fout << first_area;
        else if(bl2_y >= bl1_y) fout << (tr1_x-bl1_x)*(bl2_y-bl1_y);
        else fout << (tr1_x-bl1_x)*(tr1_y-tr2_y);
    }else if(bl2_y <= bl1_y && tr2_y >= tr1_y){
        if(bl2_x <= bl1_x && tr2_x >= tr1_x) fout << 0;
        else if(bl2_x >= bl1_x && tr2_x <= tr1_x) fout << first_area;
        else if(bl2_x >= bl1_x) fout << (tr1_y-bl1_y)*(bl2_x-bl1_x);
        else fout << (tr1_y-bl1_y)*(tr1_x-tr2_x);
    }else{
        fout << first_area;
    }

}    