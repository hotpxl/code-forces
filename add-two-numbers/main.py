class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def print(self):
        print('{} '.format(self.val), end='')
        if self.next:
            self.next.print()


class Solution:
    def addTwoNumbers(self, l1, l2):
        residue = 0
        s = []
        while True:
            if not l1 and not l2:
                break
            left = l1.val if l1 else 0
            right = l2.val if l2 else 0
            s.append((left + right + residue) % 10)
            residue = (left + right + residue) // 10
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if residue:
            s.append(residue)
        head = ListNode(s[0])
        cur = head
        for i in range(1, len(s)):
            cur.next = ListNode(s[i])
            cur = cur.next
        return head

if __name__ == '__main__':
    a = ListNode(2)
    a.next = ListNode(4)
    a.next.next = ListNode(3)
    b = ListNode(5)
    b.next = ListNode(6)
    b.next.next = ListNode(4)
    Solution().addTwoNumbers(a, b).print()
