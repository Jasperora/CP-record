class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> pq(cmp);
        for(auto& p : points){
            if(pq.size()==k){
                pq.push(p);
                pq.pop();
            }else{
                pq.push(p);
            }
        }
        vector<vector<int> > ret;
        while(pq.size()>0){
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
