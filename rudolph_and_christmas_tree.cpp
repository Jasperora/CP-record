#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        double d, h;
        cin >> n >> d >> h;
        int y[n];
        for(int j = 0; j < n; ++j){
            cin >> y[j];
        }
        double area = 0;
        for(int j = 0; j < n-1; ++j){
            if(y[j+1]-y[j]<h){
                double top = d*(h-(y[j+1]-y[j]))/h;
                // cout << top << '\n';
                area += (top+d)*(y[j+1]-y[j])/2;
            }else{
                area += d*h/2;
            }
            // cout << area << '\n';
        }
        area += d*h/2;
        cout << setprecision(17) << area << '\n';
    }
}