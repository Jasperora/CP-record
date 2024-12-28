class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size()-1;
        while(numbers[a]+numbers[b]!=target){
            int total = numbers[a] + numbers[b];
            if(total>target) --b;
            else ++a;
        }
        vector<int> ans;
        ans.push_back(a+1);
        ans.push_back(b+1);
        return ans;
    }
};