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
    void invert(TreeNode* root){
        if (!root)
            return;
        invert(root->left);
        invert(root->right);
        swap(root->left, root->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (!p && !q)
            return true;
        else if (p && !q)
            return false;
        else if (!p && q)
            return false;
        else if (p->val == q->val){
            return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
        }
        else
            return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        else if (root->left && !root->right)
            return false;
        else if (!root->left && root->right)
            return false;
        else{
            invert(root->left);
            return isSameTree(root->left, root->right);
        }
    }
};