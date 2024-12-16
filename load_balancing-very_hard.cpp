#include <iostream>
#include <fstream>
#include <set>
using namespace std;


int max(int a, int b, int c, int d){
    if(a >= b && a >= c && a >= d){
        return a;
    }else if(b >= a && b >= c && b >= d){
        return b;
    }else if(c >= a && c >= b && c >= d){
        return c;
    }else{
        return d;
    }
}

int main(){
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int N;
    fin >> N;
    pair<int, int> pos[N];
    set<int> xs, ys;
    for(int i = 0; i < N; ++i){
        fin >> pos[i].first >> pos[i].second;
        xs.insert(pos[i].first+1);
        ys.insert(pos[i].second+1);
    }
    set<int> reduced_xs, reduced_ys;
    int cnt = 0;
    for(const auto &it : xs){
        if(cnt >= int(xs.size()/3) && cnt <= int(2*xs.size()/3)) reduced_xs.insert(it);
        ++cnt;
    }
    cnt = 0;
    for(const auto &it : ys){
        if(cnt >= int(ys.size()/3) && cnt <= int(2*ys.size()/3)) reduced_ys.insert(it);
        ++cnt;
    }

    cout << xs.size() << ' ' << reduced_xs.size();
    cout << ys.size() << ' ' << reduced_ys.size();
    int dim1, dim2, dim3, dim4, M = 1001;
    for(const auto &i : xs){ // x = i
        for(const auto &j : ys){ // y = j
            dim1 = dim2 = dim3 = dim4 = 0;
            for(int k = 0; k < N; ++k){
                if(pos[k].first>i && pos[k].second>j){
                    ++dim1;
                }
                else if(pos[k].first<i && pos[k].second>j){
                    ++dim2;
                }
                else if(pos[k].first<i && pos[k].second<j){
                    ++dim3;
                }
                else{
                    ++dim4;
                }
            }
            int tmp = max(dim1, dim2, dim3, dim4);
            if(tmp < M) M = tmp;
        }
    }
    fout << M;
}