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
    
private:
    void preorder(TreeNode* root){
        if (!root)
            return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        res.clear();
        preorder(root);
        return res;
    }
};