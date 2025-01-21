class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total >> 1;
        if(nums1.size()>nums2.size()) swap(nums1, nums2);
        bool odd = total&1;

        int l = 0, r = nums1.size()-1;
        while(true){
            int i = (l+r)>>1;
            int j = half-i-2;

            int left1 = (i>=0) ? nums1[i] : -1e6-1;
            int right1 = ((i+1)<nums1.size()) ? nums1[i+1] : 1e6+1;
            int left2 = (j>=0) ? nums2[j] : -1e6-1;
            int right2 = ((j+1)<nums2.size()) ? nums2[j+1] : 1e6+1;

            if(left1<=right2 && left2<=right1){
                if(odd) return min(right1, right2);
                else return (double)(max(left1, left2)+min(right1, right2)) / 2;
            }else if(left1>right2){
                r = i-1;
            }else l = i+1;
        }
    }
};
