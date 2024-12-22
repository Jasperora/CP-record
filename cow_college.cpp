#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    ll c[N];
    for(int i = 0; i < N; ++i) cin >> c[i];
    sort(c, c+N);

    ll max=-1, tmp, tuition;
    for(int i = 0; i < N; ++i){
        tmp = c[i] * (N-i);
        if(tmp > max){
            max = tmp;
            tuition = c[i];
        }
    }
    cout << max << ' ' << tuition;
}
