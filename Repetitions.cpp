#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int ret = 0, tmp = 1;
    for(int i = 1; i < n; ++i){
        if(s[i]==s[i-1]){
            ++tmp;
        }else{
            ret = max(ret, tmp);
            tmp = 1;
        }
    }
    ret = max(ret, tmp);
    cout << ret;
}