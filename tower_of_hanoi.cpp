#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;
vector<string> output;
void move(int num, int start, int end){
    if(num >= 2){
        int middle = 6 - start - end;
        move(num-1, start, middle);
        move(1, start, end);
        move(num-1, middle, end);
    }else if(num == 1){
        output.push_back(to_string(start)+' '+to_string(end)+'\n');
        ++cnt;
    }
}

int main(){
    int n;
    cin >> n;
    move(n, 1, 3);
    cout << cnt << '\n';
    for(string s : output) cout << s;
}