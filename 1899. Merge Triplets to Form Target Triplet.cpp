class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> possible(n, true);
        for(int i = 0; i < n; ++i){
            if(triplets[i][0]>target[0] || triplets[i][1]>target[1] || triplets[i][2]>target[2])
                possible[i] = false;
        }
        bool first = false, second = false, third = false;
        for(int i = 0; i < n; ++i){
            if(possible[i]){
                if(triplets[i][0]==target[0])
                    first = true;
                if(triplets[i][1]==target[1])
                    second = true;
                if(triplets[i][2]==target[2])
                    third = true;
            }
        }
        return first&&second&&third;
    }
};
