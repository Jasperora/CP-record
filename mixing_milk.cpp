#include <iostream>
#include <fstream>
using namespace std;

// pour milk from 1 to 2
void pour(int& o1, int& m1, int& o2, int& m2){
    if(m1+m2 >= o2){
        int tmp = m2;
        m2 = o2;
        m1 = m1 + tmp - m2;
    }else{
        m2 += m1;
        m1 = 0;
    }
}

int main(){
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int o1, m1, o2, m2, o3, m3;
    fin >> o1 >> m1 >> o2 >> m2 >> o3 >> m3;

    for(int i = 0; i < 100; ++i){
        if(i%3 == 0){
            pour(o1, m1, o2, m2);
        }else if(i%3 == 1){
            pour(o2, m2, o3, m3);
        }else{
            pour(o3, m3, o1, m1);
        }
    }
    fout << m1 << '\n' << m2 << '\n' << m3;
}