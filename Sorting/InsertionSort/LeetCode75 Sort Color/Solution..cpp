class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            int tmp = nums[i];
            int j;
            for (j = i; j > 0; j--){
                if (nums[j - 1] > tmp)
                    nums[j] = nums[j - 1];
                else
                    break;
            }
            nums[j] = tmp;
        }
    }
};