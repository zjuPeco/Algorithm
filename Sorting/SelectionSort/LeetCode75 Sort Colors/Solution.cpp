class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            int minVal = nums[i];
            int minIndex = i;
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[j] < minVal){
                    minIndex = j;
                    minVal = nums[j];
                }
            }
            swap(nums[i], nums[minIndex]);
        }
    }
};