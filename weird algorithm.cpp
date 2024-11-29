#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    cout << n;
    while(1){
        if(n % 2){
            n = 3*n + 1;
            cout << ' ' << n;
        }else{
            n = n >> 1;
            cout << ' ' << n;
            if(n==1) break;
        }
    }
}