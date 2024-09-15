#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
n == # of nodes
runtime: O(n)
space: O(1)
*/
ListNode* reverse_list(ListNode* head) {
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

/*
USED SOLUTION
n == # of nodes
runtime: O(n)
space: O(n)
*/
ListNode* reverse_list2(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* rest = reverse_list2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

int main() {
    ListNode* head;
    ListNode* ans;

    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ans = reverse_list2(head);
    cout << ans << '\n';
}
