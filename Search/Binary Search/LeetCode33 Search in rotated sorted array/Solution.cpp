class Solution {
private:
    int _search(vector<int>& nums, int start, int end, int target){
        if (start > end)
            return -1;
        
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target){
            return mid;
        }
        
        if (nums[mid] < nums[start]){
            if (nums[mid] > target){
                return _search(nums, start, mid - 1, target);
            }
            else if (nums[end] >= target){
                return _search(nums, mid + 1, end, target);
            }
            else{
                return _search(nums, start, mid - 1, target);
            }
        }
        else{
            if (nums[mid] < target){
                return _search(nums, mid + 1, end, target);
            }
            else if (nums[start] <= target){
                return _search(nums, start, mid - 1, target);
            }
            else{
                return _search(nums, mid + 1, end, target);
            }
        }
    }
    
public:
    int search(vector<int>& nums, int target) {
        return _search(nums, 0, nums.size() - 1, target);
    }
};