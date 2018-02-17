/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void _serialize(TreeNode* root, stringstream& ss){
        if (root == NULL){
            ss << "*";
        }
        else{
            ss << "n" << root->val;
            _serialize(root->left, ss);
            _serialize(root->right, ss);
        }
    }
    
    TreeNode* _deserialize(stringstream& ss){
        char ch;
        ss >> ch;
        if (ch == '*'){
            return NULL;
        }
        else{
            int x;
            ss >> x;
            TreeNode* node = new TreeNode(x);
            node->left = _deserialize(ss);
            node->right = _deserialize(ss);
            return node;
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        _serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return _deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));