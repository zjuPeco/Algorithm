class Solution {
private:
    void _merge(vector<int>& vec, int start, int mid, int end){
        vector<int> vec1, vec2;
        for (int i = start; i <= mid; i++){
            vec1.push_back(vec[i]);
        }
        int m = 0;
        int n = mid + 1;
        for (int i = start; i <= end; i++){
            if (m == vec1.size()){
                break;
            }
            else if (n > end){
                vec[i] = vec1[m++];
            }
            else if (vec1[m] % 2 == 1){
                vec[i] = vec1[m++];
            }
            else if (vec[n] % 2 == 1){
                vec[i] = vec[n++];
            }
            else{
                vec[i] = vec1[m++];
            }
        }
        return;
    }
     
    void mergeSort(vector<int>& vec, int start, int end){
        if (end <= start)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);
        _merge(vec, start, mid, end);
    }
     
public:
    void reOrderArray(vector<int>& array) {
        mergeSort(array, 0, array.size() - 1);
    }
};