#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int crazyQueue(vector<int>& vec){
        if (1 == vec.size())
            return 0;
        sort(vec.begin(), vec.end());
        int big_idx = vec.size() - 1;
        int small_idx = 0;
        int big_val = vec.back();
        int small_val = vec.front();
        int res = big_val - small_val;
        while (1){
            small_idx++;
            big_idx--;
            if (small_idx > big_idx){
                break;
            }
            else if (small_idx == big_idx){
                res += max(abs(big_val - vec[small_idx]), abs(small_val - vec[small_idx]));
            }
            else{
                res = res + abs(big_val - vec[small_idx]) + abs(small_val - vec[big_idx]);
                big_val = vec[big_idx];
                small_val = vec[small_idx];
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    Solution sol;
    cout << sol.crazyQueue(vec) << endl;
}