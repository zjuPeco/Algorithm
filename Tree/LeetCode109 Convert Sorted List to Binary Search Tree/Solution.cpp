/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* generate(ListNode* head, ListNode* tail){
        if (!head || head == tail){
            return NULL;
        }
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* node = new TreeNode(slow->val);
        node->left = generate(head, slow);
        node->right = generate(slow->next, tail);
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail = NULL;
        return generate(head, tail);
    }
};