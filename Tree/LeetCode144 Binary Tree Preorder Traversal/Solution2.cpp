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
    vector<int> res;
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        res.clear();
        stack<TreeNode*> st;
        if (root)
            st.push(root);
        while (!st.empty()){
            TreeNode* tmp  = st.top();
            int val = tmp->val;
            res.push_back(val);
            st.pop();
            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }
        return res;
    }
};