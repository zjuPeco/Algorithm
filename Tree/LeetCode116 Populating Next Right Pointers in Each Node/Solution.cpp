/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if (root){
            q.push(root);
            q.push(NULL);
        }
        while (!q.empty()){
            TreeLinkNode* tmp = q.front();
            q.pop();
            if (!tmp){
                if (!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                tmp->next = q.front();
                if (tmp->left){
                    q.push(tmp->left);
                }
                if (tmp->right){
                    q.push(tmp->right);
                }
            }
        }
    }
};