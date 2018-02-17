/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> res;
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root){
            q.push(root);
            q.push(NULL);
        }
        vector<int> vec;
        while (!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if (!tmp){
                res.push_back(vec);
                if (!q.empty())
                    q.push(NULL);
                vec.clear();
            }
            else{
                vec.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        return res;
    }
};