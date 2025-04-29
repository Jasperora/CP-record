class Solution {
public:
    vector<int> times;
    bool dfs(const vector<int>& jobs, int pos, const int& k, int limit){
        if(pos == jobs.size()){
            return true;
        }else{
            bool flag = false;
            for(int i = 0; i < k; ++i){
                if(times[i] == 0){
                    if(flag) continue;
                    flag = true;
                }
                times[i] += jobs[pos];
                if(times[i] > limit){
                    times[i] -= jobs[pos];
                    continue;
                }
                if(dfs(jobs, pos + 1, k, limit))
                    return true;
                times[i] -= jobs[pos];
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        times.resize(k);
        int left = 1, right = 1e9;
        while(left <= right){
            for(int i = 0; i < k; ++i)
                times[i] = 0;
            int mid = (left + right) >> 1;
            if(dfs(jobs, 0, k, mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};