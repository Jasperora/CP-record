#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N;
    cin >> N;
    int c[N];
    for(int i = 0; i < N; ++i) cin >> c[i];

    sort(c, c+N);
    int max = -1, tmp, cnt;
    for(int i = 0; i < N; ++i){
        tmp = c[i] * (N-i);
        if(tmp > max) max = tmp;
        cnt = N-i;
    }
    cout << max << ' ' << cnt;
}
