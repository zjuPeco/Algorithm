class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int res = INT_MIN;
        int s = 0;
        for (int i = 0; i < nums.size(); i++){
            if (s < 0){
                s = nums[i];
            }
            else{
                s += nums[i];
            }
            
            if (s > res){
                res = s;
            }
        }
        return res;
    }
};