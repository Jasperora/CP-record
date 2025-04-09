class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            int left = 0, right = m*n - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                int idx = mid / n;
                int idy = mid % n;
                if(matrix[idx][idy] > target){
                    right = mid - 1;
                }else if(matrix[idx][idy] < target){
                    left = mid + 1;
                }else{
                    return true;
                }
            }
            return false;
        }
    };