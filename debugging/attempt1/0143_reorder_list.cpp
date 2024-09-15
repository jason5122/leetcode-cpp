#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
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

int main() {
    Solution solution;
    ListNode* head;

    solution = Solution();
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    solution.reorderList(head);
    cout << head << '\n';  // [1,4,2,3]

    solution = Solution();
    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    solution.reorderList(head);
    cout << head << '\n';  // [1,5,2,4,3]
}
