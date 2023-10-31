/*
1 -> 2

temp = curr->next->next        nullptr
curr->next->next = curr        [1] <-> 2
curr->next = temp              2 -> [1] -> nullptr

curr = curr->next              2 -> 1 -> [nullptr]


1 -> 2 -> 3

prev = nullptr

temp = curr->next->next        3
curr->next->next = curr        [1] <-> 2  3 -> nullptr
temp2 = curr->next             2
curr->next = prev              3 -> nullptr   2 -> [1] -> nullptr

prev = temp2                   2
curr = temp                    [3] -> nullptr   2 -> 1 -> nullptr

temp = curr->next->next        nullptr
curr->next = prev              [3] -> 2 -> 1 -> nullptr
curr = temp

n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
};

/*
USED SOLUTION
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};
