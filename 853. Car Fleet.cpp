class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int> > vp;
        for(int i = 0 ; i < position.size(); ++i){
            pair<int, int> p(position[i], speed[i]);
            vp.push_back(p);
        }
        sort(vp.rbegin(), vp.rend());
        stack<pair<int, int> > sp;
        pair<int, int> p(vp[0].first, vp[0].second);
        sp.push(p);
        for(int i = 1; i < vp.size(); ++i){
            pair<int, int> p(vp[i].first, vp[i].second);
            if(vp[i].second<=sp.top().second){
                sp.push(p);
                continue;
            }else{
                double tmp = (double)sp.top().first+(double)sp.top().second*(sp.top().first-vp[i].first)/(vp[i].second-sp.top().second);
                if(tmp > (double)target) sp.push(p);
            }
        }
        int ret = 0;
        while(!sp.empty()){
            sp.pop();
            ++ret;
        }
        return ret;
    }
};
