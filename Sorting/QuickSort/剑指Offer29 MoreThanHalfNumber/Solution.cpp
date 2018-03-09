class Solution {
private:
    int res;
     
private:
    bool _judge(vector<int>& numbers, int target){
        int count = 0;
        for (int i = 0; i < numbers.size(); i++){
            if (numbers[i] == target)
                count++;
        }
        if (count > numbers.size() / 2)
            return true;
        else
            return false;
    }
     
    int _partition(vector<int>& numbers, int start, int end){
        swap(numbers[start], numbers[rand()%(end - start + 1) + start]);
        int val = numbers[start];
        int i = start + 1;
        int j = end;
        while (i < j){
            while (numbers[i] <= val && i < j)
                i++;
            while (numbers[j] >= val && j > i)
                j--;
            if (i > j)
                break;
            swap(numbers[i], numbers[j]);
            i++;
            j--;
        }
        swap(numbers[start], numbers[j]);
        return j;
    }
     
    void _quickSort(vector<int>& numbers, int start, int end, int target){
        if (start > end)
            return;
         
        int idx = _partition(numbers, start, end);
         
        if (idx == target){
            if (_judge(numbers, numbers[idx])){
                res = numbers[idx];
            }
            else{
                res = 0;
            }
            return;
        }
        else if (idx < target){
            _quickSort(numbers, idx + 1, end, target);
        }
        else{
            _quickSort(numbers, start, idx - 1, target);
        }
    }
     
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        res = 0;
        if (0 == numbers.size())
            return res;
        int target = numbers.size() / 2;
        srand(time(NULL));
        _quickSort(numbers, 0, numbers.size() - 1, target);
        return res;
    }
};