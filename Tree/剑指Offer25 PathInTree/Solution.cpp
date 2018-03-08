/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    vector<vector<int>> res;
    
private:
    void _find(TreeNode* node, vector<int>& vec, int target){
        if (!node)
            return;
        
        vec.push_back(node->val);
        if (0 == target - node->val && !node->left && !node->right){
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        
        if (node->left)
            _find(node->left, vec, target - node->val);
        if (node->right)
            _find(node->right, vec, target - node->val);
        
        vec.pop_back();
    }
    
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> vec;
        _find(root, vec, expectNumber);
        return res;
    }
};