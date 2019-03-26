# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getLength(self, head):
        length = 0
        while head != None:
            head = head.next
            length += 1
        return length
    
    def middleNode(self, head: ListNode) -> ListNode:
        length = self.getLength(head)
        steps = length // 2
        while steps > 0:
            head = head.next
            steps -= 1
        return head
        
