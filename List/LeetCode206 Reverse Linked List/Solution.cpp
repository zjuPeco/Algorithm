/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* dummyHead = new ListNode(0);
        while (head){
            ListNode* tmp = head;
            head = head->next;
            tmp->next = dummyHead->next;
            dummyHead->next = tmp;
        }
        head = dummyHead->next;
        delete dummyHead;
        dummyHead = NULL;
        return head;
    }
};