#include <algorithm>
#include <iostream>
using namespace std;

int n;
int diff_sum(int* arr, int i, int j){
    int tmp[2*n-2], cnt=0;
    for(int k = 0; k < 2*n; ++k){
        if(k != i && k != j){
            tmp[cnt] = arr[k];
            ++cnt;
        }
    }
    int sum = 0;
    for(int k = 0; k < n-1; k++){
        sum += tmp[2*k+1] - tmp[2*k];
    }
    return sum;
}

int main() {
	cin >> n;
	int w[2*n];
	for(int i = 0; i < 2*n; ++i) cin >> w[i];

	sort(w, w + 2*n);
	int total_instability = 50001;

    for(int i = 0; i < 2*n-1; ++i){
        for(int j = i+1; j < 2*n; ++j){
            int tmp_diff_sum = diff_sum(w, i, j);
            if(tmp_diff_sum < total_instability) total_instability = tmp_diff_sum;
        }
    }
    cout << total_instability;

}
