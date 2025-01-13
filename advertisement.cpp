#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll heights[n];
    for(ll i = 0; i < n; ++i)
        cin >> heights[i];
    stack<pair<ll, ll> > s;
    ll ret = 0;
    for(ll i = 0; i < n; ++i){
        if(s.empty()){
            pair<ll, ll> p(heights[i], i);
            s.push(p);
            // cout << s.top().first << ' ' << s.top().second << '\n';
        }else{
            pair<ll, ll> p;
            p.first = heights[i];
            p.second = i;
            while(!s.empty() && heights[i]<s.top().first){
                ret = max(ret, s.top().first*(i-s.top().second));
                p.second = s.top().second;
                s.pop();
            }
            if(!s.empty()&&heights[i]==s.top().first){
                ret = max(ret, s.top().first*(i-s.top().second+1));
            }else{
                s.push(p);
                // cout << s.top().first << ' ' << s.top().second << '\n';
            }
        }
    }
    // cout << "======\n";
    while(!s.empty()){
        if(s.top().first*(n-s.top().second) > ret)
            ret = s.top().first*(n-s.top().second);
        // cout << s.top().first << ' ' << s.top().second << '\n';
        s.pop();
    }
    cout << ret;
}