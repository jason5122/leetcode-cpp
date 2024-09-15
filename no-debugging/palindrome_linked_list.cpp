/*
n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr1 = head;
        ListNode* curr2 = reverse(middle(head));
        while (curr1 && curr2) {
            if (curr1->val != curr2->val) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return !curr2;  // USED SOLUTION: This can just be `return true`.
    }

private:
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
