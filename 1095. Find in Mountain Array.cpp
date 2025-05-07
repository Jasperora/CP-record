/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findWithIndex(const int& target, MountainArray& mountainArr, int start, int end, bool increasing){
        if(start > end) return -1;
        int left = start, right = end;
        while(left <= right){
            int mid = (left + right) >> 1;
            int mid_num = mountainArr.get(mid);
            if(increasing){
                if(mid_num > target){
                    right = mid - 1;
                }else if(mid_num < target){
                    left = mid + 1;
                }else{
                    return mid;
                }
            }else{
                if(mid_num > target){
                    left = mid + 1;
                }else if(mid_num < target){
                    right = mid - 1;
                }else{
                    return mid;
                }
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 1;
        // find peak
        int peak = INT_MAX;
        while(left <= right){
            int mid = (left + right) >> 1;
            if(mid == 0){
                peak = 1;
                break;
            }else if(mid == n - 1){
                peak = n - 2;
                break;
            }
            int mid_num = mountainArr.get(mid);
            int left_num = mountainArr.get(mid-1);
            int right_num = mountainArr.get(mid+1);
            if(right_num > mid_num && mid_num > left_num){
                left = mid + 1;
            }else if(left_num > mid_num && mid_num > right_num){
                right = mid - 1;
            }else{
                peak = mid;
                break;
            }
        }
        int first_half = findWithIndex(target, mountainArr, 0, peak, true);
        if(first_half != -1) return first_half;
        return findWithIndex(target, mountainArr, peak + 1, n - 1, false);
    }
};