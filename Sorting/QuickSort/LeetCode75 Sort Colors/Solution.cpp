class Solution {
private:
    int partition(vector<int>& nums, int left, int right){
        swap(nums[left], nums[rand()%(right - left + 1) + left]);
        int i = left + 1;
        int j = right;
        while (1){
            while (i <= right && nums[i] <= nums[left]){
                i++;
            }
            while (j >= left + 1 && nums[j] >= nums[left]){
                j--;
            }
            if (i >= j)
                break;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
    
    void quickSort2(vector<int>& nums, int left, int right){
        srand(time(NULL));
        if (left >= right)
            return;
        
        int p = partition(nums, left, right);
        quickSort2(nums, left, p - 1);
        quickSort2(nums, p + 1, right);
    }
    
public:
    void sortColors(vector<int>& nums) {
        quickSort2(nums, 0, nums.size() - 1);
    }
};