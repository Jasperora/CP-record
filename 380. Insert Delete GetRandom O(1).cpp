class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> val_to_idx;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(val_to_idx.count(val))
            return false;
        nums.push_back(val);
        val_to_idx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!val_to_idx.count(val))
            return false;
        int idx = val_to_idx[val];
        // swap nums.back() and nums[idx], then pop_back()
        val_to_idx[nums.back()] = idx;
        swap(nums[idx], nums.back());
        nums.pop_back();
        val_to_idx.erase(val);
        return true;
    }
    
    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */