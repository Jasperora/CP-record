class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ret;
        vector<int> has_ball;
        for(int i = 0; i < boxes.length(); ++i){
            if(boxes[i]=='1') has_ball.push_back(i);
        }
        for(int i = 0; i < boxes.length(); ++i){
            int op = 0;
            for(auto& pos : has_ball){
                op += abs(pos-i);
            }
            ret.push_back(op);
        }
        return ret;
    }
};