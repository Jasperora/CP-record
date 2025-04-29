// recursive + memoization
class Solution1 {
public:
    unordered_map<string, double> dp;
    double serve(int A, int B){

        if(A <= 0 && B <= 0) return 0.5;
        else if(A <= 0) return 1.0;
        else if(B <= 0) return 0;

        string s = to_string(A) + "-" + to_string(B);
        if(dp.count(s)) return dp[s];
        
        return dp[s] = 0.25 * (serve(A-100, B) + serve(A-75, B-25) + serve(A-50, B-50) + serve(A-25, B-75));
    }
    double soupServings(int n) {
        // if n is too large, the stacks of dfs would overflow
        // the answer would increase as n increases
        // so if n is too large, the result would be close to 1.0
        if(n > 5000) return 1.0;

        return serve(n, n);
    }
};
// recursive
// TLE
class Solution2 {
public:
    double serve(int A, int B){
        if(A <= 0 && B <= 0) return 0.5;
        else if(A <= 0) return 1.0;
        else if(B <= 0) return 0;
        else return 0.25 * (serve(A-100, B) + serve(A-75, B-25) + serve(A-50, B-50) + serve(A-25, B-75));
    }
    double soupServings(int n) {
        return serve(n, n);
    }
};