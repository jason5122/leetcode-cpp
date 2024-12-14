/*
m == # of nodes in l1
n == # of nodes in l2
runtime: O(max(m,n))
space: O(1)
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode{};

        ListNode* curr = dummy;
        int remainder = 0;
        while (l1 || l2) {
            int sum = remainder;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            int digit = sum % 10;
            remainder = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            curr->next = new ListNode{digit};
            curr = curr->next;
        }
        if (remainder > 0) {
            curr->next = new ListNode{remainder};
        }

        return dummy->next;
    }
};
