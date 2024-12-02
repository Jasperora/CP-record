#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;
	vector<pair<int, char>> p(N);
	int tmp;
	char c;
    for(int i = 0; i < N; ++i){
        cin >> p[i].second >> p[i].first;
    }
	sort(p.begin(), p.end());
    int cnt = 10001, pos;
    for(int i = 0; i < N; ++i){
		pos = p[i].first;
        tmp = 0;
        for(int j = 0; j < N; ++j){
            if((p[j].second=='L' && p[j].first<pos) || (p[j].second=='G' && p[j].first>pos))
                ++tmp;
        }
        if(tmp < cnt) cnt = tmp;
    }
    cout << cnt;

}