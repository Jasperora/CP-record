#include <iostream>
#include <set>
using namespace std;

int main(){
    int N, tmp, cnt = 0;
    cin >> N;
    set<int> s;
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int element : s){
        ++cnt;
    }
    cout << cnt;
}