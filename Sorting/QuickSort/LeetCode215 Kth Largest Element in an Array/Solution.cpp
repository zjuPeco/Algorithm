class Solution {
private:
    int partition(vector<int>& nums, int start, int end){
        swap(nums[start], nums[rand()%(end - start + 1) + start]);
        int val = nums[start];
        int j = start;
        for (int i = start + 1; i <= end; i++){
            if (nums[i] < val){
                swap(nums[++j], nums[i]);
            }
        }
        swap(nums[start], nums[j]);
        return j;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        srand(time(NULL));
        int idx = partition(nums, start, end);
        while (nums.size() - idx != k){
            if (nums.size() - idx > k){
                start = idx + 1;
                idx = partition(nums, start, end);
            }
            else{
                end = idx - 1;
                idx = partition(nums, start, end);
            }
        }
        return nums[idx];
        
    }
};