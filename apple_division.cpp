#include <iostream>
#include <vector>
using namespace std;


int n;
vector<long long> p;
long long recursive_add(int i, long long sum1, long long sum2){
    if(i==n) return abs(sum1-sum2);
    return min(recursive_add(i+1, sum1+p[i], sum2), recursive_add(i+1, sum1, sum2+p[i]));
}

int main(){
    cin >> n;
    p.resize(n);

    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    cout << recursive_add(0, 0, 0);
}