#include <iostream>
#include <stack>
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
// space: O(n)
bool is_palindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    stack<int> seen;

    // find halfway point
    while (fast != nullptr) {
        seen.push(slow->val);

        fast = fast->next;
        if (fast == nullptr) break;
        fast = fast->next;

        slow = slow->next;
    }

    // slow is now pointing to the middle node (second middle if even)
    // stack now has the first half of nodes
    while (slow != nullptr) {
        if (slow->val != seen.top()) return false;

        slow = slow->next;
        seen.pop();
    }
    return seen.empty();
}

// n == # of nodes
// runtime: O(n)
// space: O(1)
bool is_palindrome2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // find halfway point
    while (fast != nullptr) {
        fast = fast->next;
        if (fast == nullptr) break;
        fast = fast->next;

        slow = slow->next;
    }

    // slow is now pointing to the middle node (second middle if even)

    // reverse the list from halfway to the end
    ListNode* curr = slow;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        ListNode* next = curr->next;  // save next node pointer

        curr->next = prev;  // set current node pointer to previous...
        prev = curr;        // ...current node is now the new previous

        if (next == nullptr) break;
        curr = next;  // restore next node pointer to curr
    }

    // curr is now pointing to the last node

    ListNode* first = head;
    ListNode* last = curr;
    while (first != nullptr && last != nullptr) {
        if (first->val != last->val) return false;

        first = first->next;
        last = last->next;
    }
    return true;
}

int main() {
    ListNode n4(1);
    ListNode n3(2, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    bool result = is_palindrome2(&n1);
    cout << result << '\n';  // true

    n2 = ListNode(2);
    n1 = ListNode(1, &n2);
    result = is_palindrome2(&n1);
    cout << result << '\n';  // false
}
