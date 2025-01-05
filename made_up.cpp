#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N], B[N], C[N];
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];
    for(int i = 0; i < N; ++i) cin >> C[i];

    map<int, int> A_cnt;
    for(int i = 0; i < N; ++i){
        if(!A_cnt.count(A[i])) A_cnt[A[i]] = 0;
        ++A_cnt[A[i]];
    }
    map<int, int> B_equal_A_num;
    for(int i = 0; i < N; ++i) B_equal_A_num[i+1] = A_cnt[B[i]];
    map<int, int> C_cnt;
    for(int i = 0; i < N; ++i){
        if(!C_cnt.count(C[i])) C_cnt[C[i]] = 0;
        ++C_cnt[C[i]];
    }
    long long ans = 0;
    for(int i = 1; i <= N; ++i){
        if(B_equal_A_num.count(i) && C_cnt.count(i))
            ans += (long long)B_equal_A_num[i] * C_cnt[i];
    }
    cout << ans;
}