#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> s, t, c, a, b, p, m;
vector<int> has_air_conditioner;
vector<int> prices;
void search(int idx){
    if(idx==M){
        int decrease_temp[101], price = 0;
        fill(decrease_temp, decrease_temp+101, 0);
        for(int i = 0; i < has_air_conditioner.size(); ++i){
            price += m[has_air_conditioner[i]];
            for(int j = a[has_air_conditioner[i]]; j <= b[has_air_conditioner[i]]; ++j){
                decrease_temp[j] += p[has_air_conditioner[i]];
            }
        }
        // cout << '\n';
        // for(int i = 0; i < has_air_conditioner.size(); ++i){
        //     cout << has_air_conditioner[i] << ' ';
        // }
        // cout << '\n';
        // for(int i = 1; i <= 100; ++i){
        //     cout << decrease_temp[i] << ' ';
        // }
        // cout << '\n';
        bool cool_down = true;
        for(int i = 0; i < N; ++i){
            for(int j = s[i]; j <= t[i]; ++j){
                cool_down &= (decrease_temp[j]>=c[i]);
            }
        }
        if(!cool_down) prices.push_back(-1);
        else prices.push_back(price);

    }else{
        search(idx+1);
        has_air_conditioner.push_back(idx);
        search(idx+1);
        has_air_conditioner.pop_back();
    }
}

int main(){
    cin >> N >> M;
    s.resize(N);
    t.resize(N);
    c.resize(N);
    a.resize(M);
    b.resize(M);
    p.resize(M);
    m.resize(M);
    for(int i = 0; i < N; ++i) cin >> s[i] >> t[i] >> c[i];
    for(int i = 0; i < M; ++i) cin >> a[i] >> b[i] >> p[i] >> m[i];

    search(0);
    int ans = 10001;
    for(int& pr : prices){
        if(pr>=0 && pr<ans) ans = pr;
    }
    cout << ans;
}