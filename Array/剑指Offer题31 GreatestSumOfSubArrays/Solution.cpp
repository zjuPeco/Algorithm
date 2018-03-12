class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxSum = array[0];
        int s = array[0];
        for (int i = 1; i < array.size(); i++){
            if (s > 0){
                s += array[i];
            }
            else{
                s = array[i];
            }
            maxSum = max(maxSum, s);
        }
        return maxSum;
    }
};