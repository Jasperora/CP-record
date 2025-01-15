class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > min_heap;
        for(auto& n : nums){
            if(min_heap.size()==k){
                min_heap.push(n);
                min_heap.pop();
            }else{
                min_heap.push(n);
            }
        }
        return min_heap.top();
    }
};