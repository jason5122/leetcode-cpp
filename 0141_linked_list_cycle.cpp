#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// n == # of nodes
// runtime: O(n)
// space: O(n)
bool has_cycle(ListNode* head) {
    unordered_set<ListNode*> seen;

    ListNode* curr = head;
    while (curr != NULL) {
        if (seen.find(curr) != seen.end()) return true;

        seen.insert(curr);
        curr = curr->next;
    }

    return false;
}

// n == # of nodes
// runtime: O(n)
// space: O(1)
bool has_cycle2(ListNode* head) {
    if (head == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL) {
        if (slow == fast) return true;

        slow = slow->next;
        fast = fast->next;
        if (fast != NULL) fast = fast->next;
    }

    return false;
}

int main() {
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(0);
    ListNode n4(-4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n2;

    bool result = has_cycle2(&n1);
    cout << result << '\n';
}
