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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int start1, int end1, int start2, int end2){
        if (start1 > end1 || start2 > end2)
            return NULL;
        
        int val = postorder[end2];
        TreeNode* node = new TreeNode(val);
        int idx = -1;
        for (int i = start1; i <= end1; i++){
            if (inorder[i] == val){
                idx = i;
                break;
            }
        }
        int leftNum = idx - start1;
        int rightNum = end1 - idx;
        node->left = _buildTree(inorder, postorder, start1, idx - 1, start2, start2 + leftNum - 1);
        node->right = _buildTree(inorder, postorder, idx + 1, end1, end2 - rightNum, end2 - 1);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return _buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};