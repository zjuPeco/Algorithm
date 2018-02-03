class Solution {
private:
    void merge(vector<int>& nums, int head, int mid, int tail){
        vector<int> vec;
        for (int i = head; i <= mid; i++){
            vec.push_back(nums[i]);
        }
        
        int m = head;
        int n = mid + 1;
        for (int i = head; i <= tail; i++){
            if (m > mid){
                nums[i] = nums[n];
                n++;
            }
            else if (n > tail){
                nums[i] = vec[m - head];
                m++;
            }
            else if (vec[m - head] < nums[n]){
                nums[i] = vec[m - head];
                m++;
            }
            else{
                nums[i] = nums[n];
                n++;
            }
        }
    }
    
    void mergeSort(vector<int>& nums, int head, int tail){
        if (head >= tail)
            return;
        int mid = head + (tail - head) / 2;
        mergeSort(nums, head, mid);
        mergeSort(nums, mid + 1, tail);
        merge(nums, head, mid, tail);
    }
    
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};