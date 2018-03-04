class Solution {
private:
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> res;
    
private:
    void getDict(vector<int>& nums){
        for (int i = 0; i < nums.size(); i++){
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;
        }
    }
    
    void getMinHeap(int k){
        for (auto iter = mp.begin(); iter != mp.end(); iter++){
            if (q.size() == k){
                if (iter->second > q.top().first){
                    q.pop();
                    q.push(make_pair(iter->second, iter->first));
                }
            }
            else{
                q.push(make_pair(iter->second, iter->first));
            }
        }
    }
    
    void getTopK(){
        while (!q.empty()){
            res.insert(res.begin(), q.top().second);
            q.pop();
        }
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        getDict(nums);
        getMinHeap(k);
        getTopK();
        return res;
    }
};