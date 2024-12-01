#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    int br_b, br_a, sl_b, sl_a, go_b, go_a, pl_b, pl_a;
    fin >> br_b >> br_a >> sl_b >> sl_a >> go_b >> go_a >> pl_b >> pl_a;

    int br_sl, sl_go, go_pl;
    go_pl = pl_a - pl_b;
    sl_go = pl_a + go_a - pl_b - go_b;
    br_sl = pl_a + go_a + sl_a - pl_b - go_b - sl_b;
    fout << br_sl << '\n' << sl_go << '\n' << go_pl;
}