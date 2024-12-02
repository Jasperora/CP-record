#include <iostream>
using namespace std;

int cal_dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int N;
    cin >> N;
    int x[N], y[N];
    for(int i = 0; i < N; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < N; ++i){
        cin >> y[i];
    }
    int max = -1, tmp;
    for(int i = 0; i < N-1; ++i){
        for(int j = i+1; j < N; ++j){
            tmp = cal_dist(x[i], y[i], x[j], y[j]);
            if(tmp > max) max = tmp;
        }
    }
    cout << max;
}