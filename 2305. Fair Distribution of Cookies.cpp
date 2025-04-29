// dfs + binary search pruning
class Solution1 {
public:
    vector<int> children;
    bool dfs(const vector<int>& cookies, int pos, const int& k, int limit){
        if(pos == cookies.size()){
            return true;
        }else{
            // to avoid same cookies to be distributed to two people
            // that two people both don't have cookies
            // just give the cookies to one of them
            bool flag = false;
            for(int i = 0; i < k; ++i){
                if(children[i] == 0){
                    if(flag) continue;
                    flag = true;
                }
                children[i] += cookies[pos];
                // pruning
                if(children[i] > limit){
                    children[i] -= cookies[pos];
                    continue;
                }
                if(dfs(cookies, pos + 1, k, limit))
                    return true;
                children[i] -= cookies[pos];
            }
        }
        return false;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        children.resize(k, 0);
        // want to make pruning appear earlier
        sort(cookies.rbegin(), cookies.rend());
        int left = 1, right = 8e5;
        while(left <= right){
            // because dfs might not completely finish
            // some values might still be in children
            // need to reset them
            for(int i = 0; i < k; ++i){
                children[i] = 0;
            }
            int mid = (left + right) >> 1;
            if(dfs(cookies, 0, k, mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
// brute force dfs
class Solution2 {
public:
    int ret;
    vector<int> children;
    void dfs(const vector<int>& cookies, int pos, const int& k){
        if(pos == cookies.size()){
            int mx = 0;
            for(int i = 0; i < k; ++i)
                mx = max(mx, children[i]);
            ret = min(ret, mx);
        }else{
            for(int i = 0; i < k; ++i){
                children[i] += cookies[pos];
                dfs(cookies, pos + 1, k);
                children[i] -= cookies[pos];
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        ret = 8e5;
        children.resize(k, 0);
        dfs(cookies, 0, k);
        return ret;
    }
};