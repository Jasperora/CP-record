// segment tree
class NumArray {
public:
    vector<int> segmentTree;
    int n;
    void buildTree(const vector<int>& nums, int pos, int left, int right){
        if(left == right){
            segmentTree[pos] = nums[left];
            return;
        }else{
            int mid = (left + right) >> 1;
            buildTree(nums, 2 * pos + 1, left, mid);
            buildTree(nums, 2 * pos + 2, mid+1, right);
            segmentTree[pos] = segmentTree[2*pos+1] + segmentTree[2*pos+2];;
        }
    }
    void updateTree(int pos, int left, int right, int index, int val){
        if(left == right){
            segmentTree[pos] = val;
            return;
        }else{
            int mid = (left + right) >> 1;
            if(index <= mid)
                updateTree(2 * pos + 1, left, mid, index, val);
            else
                updateTree(2 * pos + 2, mid+1, right, index, val);
            segmentTree[pos] = segmentTree[2*pos+1] + segmentTree[2*pos+2];
        }
    }
    int rangeSum(int pos, int left, int right, int qleft, int qright){
        if(qleft <= left && qright >= right)
            return segmentTree[pos];
        if(qleft > right || qright < left)
            return 0;
        int mid = (left + right) >> 1;
        return rangeSum(2*pos+1, left, mid, qleft, qright) + rangeSum(2*pos+2, mid+1, right, qleft, qright);
    }
    NumArray(vector<int>& nums) {
        if(!nums.empty()){
            n = nums.size();
            segmentTree.resize(4*n, 0);
            buildTree(nums, 0, 0, n-1);
        }
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */