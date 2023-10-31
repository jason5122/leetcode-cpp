/*
1 -> 2 -> 3

curr = 1
next = 2
stk = [3]

1 -> 3 -> 2
curr = 2
next = nullptr
stk = []

n == length of linked list
runtime: O(2n)
space: O(n)
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        stack<ListNode*> stk;

        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->next;
            len++;
        }

        curr = head;
        ListNode* next = curr->next;
        int count = 0;
        while (curr != nullptr) {
            if (stk.empty()) break;
            if (count == len / 2) break;

            ListNode* last = stk.top();

            curr->next = last;
            last->next = next;

            curr = next;
            next = curr->next;

            stk.pop();
            count++;
        }
        curr->next = nullptr;
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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr, *curr = slow, *tmp;
        while (curr != nullptr) {
            tmp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        ListNode *first = head, *second = prev;
        while (second->next != nullptr) {
            tmp = first->next;
            first->next = second;
            first = tmp;

            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};

/*
USED SOLUTION
n == length of linked list
runtime: O(n)
space: O(1)
*/
class Solution {
    ListNode* middle_node(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse_list(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* next = reverse_list(curr->next);
        curr->next->next = curr;
        curr->next = nullptr;
        return next;
    }

    void interleave_lists(ListNode* head1, ListNode* head2) {
        while (head1->next != nullptr && head2->next != nullptr) {
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }
    }

public:
    void reorderList(ListNode* head) {
        ListNode* middle = middle_node(head);
        ListNode* reversed_half = reverse_list(middle);
        interleave_lists(head, reversed_half);
    }
};
