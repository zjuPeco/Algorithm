class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int idx = 0;
        if (strs.size() == 0)
            return res;
        
        while (1){
            if (idx >= strs[0].length())
                return res;
            char tmp = strs[0][idx];
            for (int i = 1; i < strs.size(); i++){
                if (idx >= strs[i].length() || strs[i][idx] != tmp){
                    return res;
                }
            }
            idx++;
            res += tmp;
        }
    }
};