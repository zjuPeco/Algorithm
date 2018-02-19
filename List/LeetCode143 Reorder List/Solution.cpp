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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        
        // get the mid position
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* head2 = p1->next;
        p1->next = NULL;
        
        // invert part2
        ListNode* dummyHead = new ListNode(0);
        p2 = head2;
        while (p2){
            ListNode* tmp = dummyHead->next;
            dummyHead->next = p2;
            p1 = p2->next;
            p2->next = tmp;
            p2 = p1;
        }
        head2 = dummyHead->next;
        delete dummyHead;
        
        // merge two parts
        p1 = head;
        p2 = head2;
        while (p1){
            ListNode* tmp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = tmp;
        }
    }
};