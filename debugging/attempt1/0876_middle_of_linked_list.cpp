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
ListNode* middle_node(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast == nullptr) return slow;
        fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

int main() {
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode* result = middle_node(&n1);
    bool is_middle = result == &n3;
    cout << is_middle << '\n';  // true
}
