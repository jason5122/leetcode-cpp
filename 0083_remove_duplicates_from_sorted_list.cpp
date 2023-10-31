#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// n == # of nodes
// runtime: O(n)
// space: O(1)
ListNode* delete_duplicates(ListNode* head) {
    if (head == nullptr) return head;

    int val = head->val;
    ListNode* curr = head->next;
    ListNode* prev = head;
    while (curr != nullptr) {
        if (curr->val == val) {
            prev->next = curr->next;  // skip over
        } else {
            prev = curr;
            val = curr->val;
        }

        curr = curr->next;
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2)));
    ListNode* result = delete_duplicates(head);
    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';

    head = new ListNode(
        1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    result = delete_duplicates(head);
    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << '\n';
}
