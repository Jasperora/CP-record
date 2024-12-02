#include <iostream>
using namespace std;


int main(){
    int N;
    cin >> N;
    int p[N];
    for(int i = 0; i < N; ++i) cin >> p[i];

    int sum, cnt = 0;
    for(int i = 0; i <= N-1; ++i){
        for(int j = i; j <= N-1; ++j){
            sum = 0;
            for(int k = i; k <= j; ++k){
                sum += p[k];
            }
            for(int k = i; k <= j; ++k){
                if(p[k] * (j-i+1) == sum){
                    ++cnt;
                    break;
                }
            }
        }
    }
    cout << cnt;

}