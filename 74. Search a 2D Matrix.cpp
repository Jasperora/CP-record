class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        int row_low = 0, row_high = row_num-1;

        int row;
        while(true){
            int mid = int((row_low+row_high)/2);
            if(target > matrix[mid][col_num-1]){
                row_low = mid;
            }else if(target < matrix[mid][0]){
                row_high = mid;
            }else if(matrix[mid][0]<=target && target<=matrix[mid][col_num-1]){
                row = mid;
                break;
            }
            if(matrix[row_low][0]<=target && target<=matrix[row_low][col_num-1]){
                row = row_low;
                break;
            }
            if(matrix[row_high][0]<=target && target<=matrix[row_high][col_num-1]){
                row = row_high;
                break;
            }
            if(row_low==row_high){
                row = row_low;
                break;
            }
            if(row_low==row_high-1){
                if(target>matrix[row_high][col_num-1]){
                    row = row_high;
                    break;
                }
                if(target<matrix[row_low][0]){
                    row = row_low;
                    break;
                }
                if(target>matrix[row_low][col_num-1]&&target<matrix[row_high][0])
                    return false;
            }
        }
        int col_low = 0, col_high = col_num-1;
        while(true){
            if(matrix[row][col_low]==target || matrix[row][col_high]==target){
                return true;
            }
            int mid = int((col_low+col_high)/2);
            if(target > matrix[row][mid]){
                col_low = mid;
            }else if(target < matrix[row][mid]){
                col_high = mid;
            }else{
                return true;
            }
            if((col_low==col_high-1||col_low==col_high)&&matrix[row][col_low]!=target&&matrix[row][col_high]!=target){
                return false;
            }
        }
        return false;
    }
};
