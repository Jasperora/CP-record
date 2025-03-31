class Solution {
    public:
        void cal(const vector<int>& p1, const vector<int>& p2, vector<int>& edge){
            edge[0] = p2[0]-p1[0];
            edge[1] = p2[1]-p1[1];
        }
        int squarelen(const vector<int>& vec){
            return vec[0]*vec[0] + vec[1]*vec[1];
        }
        bool vertical(const vector<int>& vec1, const vector<int>& vec2){
            return vec1[0]*vec2[0] + vec1[1]*vec2[1] == 0;
        }
        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            vector<int> v12(2), v13(2), v14(2);
            cal(p1, p2, v12);
            cal(p1, p3, v13);
            cal(p1, p4, v14);
            int len12 = squarelen(v12);
            int len13 = squarelen(v13);
            int len14 = squarelen(v14);
            if(len12==0 || len13==0 || len14==0) return false;
            if(len12==len13){
                if(v12[0]+v13[0]==v14[0] && v12[1]+v13[1]==v14[1] && vertical(v12, v13)) return true;
                else return false;
            }else if(len12==len14){
                if(v12[0]+v14[0]==v13[0] && v12[1]+v14[1]==v13[1] && vertical(v12, v14)) return true;
                else return false;
            }else if(len13==len14){
                if(v14[0]+v13[0]==v12[0] && v14[1]+v13[1]==v12[1] && vertical(v14, v13)) return true;
                else return false;
            }else return false;
        }
    };