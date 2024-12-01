#include <iostream>
#include <cstring> // for memset
using namespace std;

const int N = 5000001;
long long num[N];
bool is_prime[N];


void prepare(){
    memset(num, 0, sizeof(num));
    memset(is_prime, true, sizeof(is_prime));

    int cnt = 0;
    is_prime[2] = true;

    // num[i] will record the # of prime factors of i
    for(int i = 2; i < N; ++i){
        if(is_prime[i]){
            for(int j = i; j < N; j += i){
                is_prime[j] = false;
                int tmp = j;
                while(tmp % i == 0){
                    ++num[j];
                    tmp /= i;
                }
            }
        }
    }

    // prefix sum
    for(int i = 2; i < N; ++i){
        num[i] = num[i-1] + num[i];
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prepare();
    int t;
    cin >> t;
    int a, b;
    while(t--){
        cin >> a >> b;
        cout << num[a] - num[b] << '\n';
    }
}