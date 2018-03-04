class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    
private:
    void getMinHeap(vector<int>& nums, int k){
        for (int i = 0; i < nums.size(); i++){
            if (pq.size() == k){
                if (nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else{
                pq.push(nums[i]);
            }
        }
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        getMinHeap(nums, k);
        return pq.top();
    }
};