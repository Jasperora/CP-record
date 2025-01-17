class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool cnt = false;
        for(auto& b : derived)
            cnt ^= b;
        return cnt==false;
    }
};