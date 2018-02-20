/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* deleteNode(ListNode* head, ListNode* p){
        if (p == head){
            head = head->next;
            delete p;
            p = NULL;
            return head;
        }
        
        ListNode* tmp = NULL;
        if (!p->next){
            tmp = head;
            while (tmp->next != p){
                tmp = tmp->next;
            }
            tmp->next = NULL;
            delete p;
            p = NULL;
            return head;
        }
        
        tmp = p->next;
        p->val = tmp->val;
        p->next = tmp->next;
        delete tmp;
        tmp = NULL;
        return head;
    }
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0)
            return head;
        
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < n - 1; i++){
            p1 = p1->next;
            if (!p1)
                return NULL;
        }
        
        while (p1->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        head = deleteNode(head, p2);
        return head;
    }
};