/*
n == length of linked list
runtime: O(2n)
space: O(1)
*/
class Solution {
    int length(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            len++;
        }
        return len;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);

        int target = len - n;
        int i = 0;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (i == target) {
                prev->next = curr->next;
                break;
            } else {
                prev = curr;
                curr = curr->next;
                i++;
            }
        }
        return dummy->next;
    }
};

/*
USED SOLUTION
n == length of linked list
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (n--) fast = fast->next;

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = slow;
        while (fast != nullptr) {
            prev = curr;
            curr = curr->next;

            fast = fast->next;
        }

        prev->next = curr->next;
        return dummy->next;
    }
};
