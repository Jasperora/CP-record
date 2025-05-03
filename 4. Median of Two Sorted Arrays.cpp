class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = total >> 1;
        // binary search in smaller vector
        if(n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // want nums1[0..mid] and nums2[0..len-mid]
        // to form the first part
        //           i
        // [1  2  3  4]  5  6  7
        //           j
        // [2  4  6  8] 10 12 24 26 18 20
        // split to left and right partition
        int left = 0, right = m - 1;
        while(true){
            int i = (left + right) >> 1;
            // actually i+1 elements in nums1
            // and need to -1 for index staring at 0
            int j = half - (i+1) - 1;
            // cout << i << ' ' << j << '\n';

            // if i < 0, it means no elements in nums1 are in left partition
            // no need to check if Aleft <= Bright
            int Aleft = (i >= 0) ? nums1[i] : INT_MIN;
            // if i+1 >= m, it means all elements in nums1 are in left partition
            // no need to check if Bleft <= Aright
            int Aright = (i+1 < m) ? nums1[i+1] : INT_MAX;
            int Bleft = (j >= 0) ? nums2[j] : INT_MIN;
            int Bright = (j+1 < n) ? nums2[j+1] : INT_MAX;
            if(Aleft <= Bright && Bleft <= Aright){
                if(total & 1) return min(Aright, Bright);
                else return (max(Aleft, Bleft) + min(Aright, Bright)) * 1.0 / 2;
            }else if(Aleft > Bright){
                // i should decrease
                right = i - 1;
            }else{
                left = i + 1;
            }
        }
        // impossible to be here
        return -1.0;
    }
};