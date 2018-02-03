class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        // separate the list
        ListNode *slow = head, *fast = head, *prev;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(slow);
        return merge(head1, head2);
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode * dummyHead = new ListNode(0);
        ListNode *p = dummyHead;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            }
            else {
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }
        }
        if (head1)
            p->next = head1;
        if (head2)
            p->next = head2;
        return dummyHead->next;
    }
};