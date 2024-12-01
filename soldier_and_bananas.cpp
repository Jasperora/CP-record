#include <iostream>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;

    int spending = (1+w) * k * w / 2;
    if (spending > n) cout << spending - n;
    else cout << 0;
}