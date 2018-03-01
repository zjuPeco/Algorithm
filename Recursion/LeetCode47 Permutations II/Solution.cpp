class Solution {
private:
    vector<vector<int>> res;
    
private:
    void dfs(vector<int> nums, int idx){
        if (idx == nums.size() - 1){
            res.push_back(nums);
        }
        
        for (int i = idx; i < nums.size(); i++){
            if (i != idx && nums[i] == nums[idx])
                continue;
            swap(nums[i], nums[idx]);
            dfs(nums, idx + 1);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0)
            return res;
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, 0);
        
        return res;
    }
};