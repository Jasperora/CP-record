#include <iostream>
using namespace std;

long long max(long long a, long long b){
    if(a>=b) return a;
    else return b;
}
long long min(long long a, long long b){
    if(a<=b) return a;
    else return b;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        long long W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        if(y2-y1+h > H && x2-x1+w > W){
            cout << -1 << '\n';
            continue;
        }
        
        long long displacement_left = 1e8, displacement_right = 1e8, displacement_top = 1e8, displacement_bottom = 1e8;
        if(x2-x1+w <= W) displacement_left = max(w-x1, 0), displacement_right = max(w-(W-x2), 0);
        if(y2-y1+h <= H) displacement_top = max(h-(H-y2), 0), displacement_bottom = max(h-y1, 0);
        cout << min(displacement_left, min(displacement_right, min(displacement_top, displacement_bottom))) << '\n';
    }
}