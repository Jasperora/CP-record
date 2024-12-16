#include <iostream>
#include <map>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    map<long, long> m;
    for(int i = 0; i < Q; ++i){
        int flag;
        cin >> flag;
        if(flag==0){
            long long k, v;
            cin >> k >> v;
            m[k] = v;
        }else{
            long long k;
            cin >> k;
            cout << m[k] << '\n';
        }
    }
}