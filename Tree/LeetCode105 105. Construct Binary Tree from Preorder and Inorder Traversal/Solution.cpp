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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if (preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        
        int value = preorder[preStart];
        TreeNode* newNode = new TreeNode(value);
        int idx = -1;
        for (int i = inStart; i <= inEnd; i++){
            if (value == inorder[i]){
                idx = i;
                break;
            }
        }
        int leftNum = idx - inStart;
        int rightNum = inEnd - idx;
        newNode->left = _buildTree(preorder, inorder, preStart + 1, preStart + leftNum, inStart, idx - 1);
        newNode->right = _buildTree(preorder, inorder, preStart + leftNum + 1, preEnd, idx + 1, inEnd);
        return newNode;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return _buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};