#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main(){
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int N;
    fin >> N;
    int heights[N];
    int min_height = 1000001, max_height = 0;
    for(int i = 0; i < N; ++i){
        fin >> heights[i];
        if(heights[i]>max_height) max_height = heights[i];
        if(heights[i]<min_height) min_height = heights[i];
    }
    if(N==2){
        if(heights[0] > heights[1]) fout << 1;
        else fout << 0;
    }
    int wrong_idx;
    if(heights[0]>heights[1]){
        wrong_idx = 0;
    }else if(heights[N-2]>heights[N-1]){
        wrong_idx = N-1;
    }else{
        for(int i = 1; i <= N-2; ++i){
            if((heights[i]<heights[i-1]&&heights[i]<heights[i+1])||(heights[i]>heights[i-1]&&heights[i]>heights[i+1])&&heights[i-1]<=heights[i+1]){
                wrong_idx = i;
                // cout << heights[i-1] << ' ' << heights[i] << ' ' << heights[i+1] << '\n';
                break;
            }
        }
    }
    int right_idx;
    if(heights[wrong_idx]<=min_height){
        right_idx = 0;
    }else if(heights[wrong_idx]>=max_height){
        right_idx = N-1;
    }else{
        for(int i = 0; i <= N-2; ++i){
            if(heights[i]<=heights[wrong_idx] && heights[i+1]>=heights[wrong_idx] && i+1!=wrong_idx){
                right_idx = i+1;
                break;
            }
        }
    }
    set<int> middle_num;
    // cout << "w: " << wrong_idx << " r: " << right_idx << '\n';
    // cout << "w: " << heights[wrong_idx] << " r: " << heights[right_idx] << '\n';
    if(right_idx>wrong_idx){
        for(int i = wrong_idx+1; i < right_idx; ++i){
            middle_num.insert(heights[i]);
        }
    }else{
        for(int i = right_idx; i < wrong_idx; ++i){
            middle_num.insert(heights[i]);
        }
    }
    middle_num.erase(heights[wrong_idx]);
    for(auto& s : middle_num) cout << s << '\n';
    fout << middle_num.size();
    
}