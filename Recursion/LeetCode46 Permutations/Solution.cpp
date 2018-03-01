class Solution {
private:
    vector<vector<int>> res;
    
private:
    void dfs(vector<int> nums, int idx){
        if (idx == nums.size() - 1){
            res.push_back(nums);
        }
        for (int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            dfs(nums, idx + 1);
        }
        return;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return res;
        
        dfs(nums, 0);
        
        return res;
    }
};