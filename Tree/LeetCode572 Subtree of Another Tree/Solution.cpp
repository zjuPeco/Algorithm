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
    bool check(TreeNode* s, TreeNode* t){
        if (s && !t)
            return false;
        
        if (!s && t)
            return false;
        
        if (!s && !t)
            return true;
        
        if (s->val == t->val){
            return check(s->left, t->left) & check(s->right, t->right);
        }
        
        return false;
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t)
            return true;
        
        bool res = false;
        
        if (s && t){
            if (s->val == t->val){
                res = check(s, t);
            }
            if (!res){
                res = isSubtree(s->left, t);
            }
            if (!res){
                res = isSubtree(s->right, t);
            }
        }
        
        return res;
    }
};