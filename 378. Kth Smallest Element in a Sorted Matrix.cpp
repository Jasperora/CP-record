class Solution {
    public:
        int n;
        int countLessThanEqual(const vector<vector<int>>& matrix, int mid, int& smaller, int& larger){
            int cnt = 0;
            int row = n - 1;
            int col = 0;
            while(row >= 0 && col < n){
                int num = matrix[row][col];
                if(num > mid){
                    // search smaller num
                    --row;
                    larger = min(larger, num);
                }else{
                    // search larger num
                    ++col;
                    smaller = max(smaller, num);
                    cnt += row + 1;
                }
            }
            return cnt;
        }
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            n = matrix.size();
            int left = matrix[0][0], right = matrix[n-1][n-1];
            int prev_cnt = -1;
            while(left <= right){
                int mid = (left + right) >> 1;
                int smaller = left, larger = right;
                int cnt = countLessThanEqual(matrix, mid, smaller, larger);
                // to prevent case like matrix = [[1,2],[1,3]], k = 1
                // cnt will always be 2 instead of 1 => TLE
                // 1st and 2nd smallest num are the same
                if(prev_cnt == cnt) return left;
                if(cnt > k) right = smaller;
                else if(cnt < k) left = larger;
                else return smaller;
                prev_cnt = cnt;
            }
            // impossible to go here
            return -1;
        }
    };