# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def merge(self, head1, head2):
        dummyHead = ListNode(0)
        cur = dummyHead
        while head1 and head2:
            if head1.val < head2.val:
                cur.next = head1
                head1 = head1.next
                cur = cur.next
            else:
                cur.next = head2
                head2 = head2.next
                cur = cur.next
        if head1:
            cur.next = head1
        if head2:
            cur.next = head2
        return dummyHead.next
        
    
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        slow = head
        fast = head
        prev = slow
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None
        head1 = self.sortList(head)
        head2 = self.sortList(slow)
        return self.merge(head1, head2)
        