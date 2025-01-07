#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, num;
    cin >> n;
    stack<pair<int, int> > s;
    for(int i = 1; i <= n; ++i){
        cin >> num;
        if(s.empty()){
            cout << 0 << ' ';
            pair<int, int> p(num, i);
            s.push(p);
        }else{
            while(!s.empty() && num<=s.top().first){
                s.pop();
            }
            if(s.empty()) cout << 0 << ' ';
            else cout << s.top().second << ' ';

            pair<int, int> p(num, i);
            s.push(p);
        }
    }
}