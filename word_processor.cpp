#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("word.in");
    ofstream fout("word.out");

    int N, K;
    vector<string> words;

    fin >> N >> K;
    for(int i = 0; i < N; ++i){
        string s;
        fin >> s;
        words.push_back(s);
    }

    int remain = K;
    for(int i = 0; i < N; ++i){
        if(remain >= words[i].length()){
            if(remain==K) fout << words[i];
            else fout << ' ' << words[i];
            remain -= words[i].length();
        }else{
            fout << '\n';
            remain = K;
            --i;
        }
    }
}