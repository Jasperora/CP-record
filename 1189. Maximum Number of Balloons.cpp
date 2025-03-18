class Solution {
    public:
        int maxNumberOfBalloons(string text) {
            map<char, int> m;
            for(auto& c : text){
                if(c=='b'||c=='a'||c=='l'||c=='o'||c=='n')
                    m[c]++;
            }
            int ret = 10000;
            char cc[5] = {'b', 'a', 'n', 'o', 'l'};
            for(int i = 0; i < 5; ++i){
                if(!m.count(cc[i])) return 0;
                if(i<3){
                    ret = min(ret, m[cc[i]]);
                }else{
                    ret = min(ret, m[cc[i]]>>1);
                }
            }
            return ret;
        }
    };