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
ListNode* remove_elements(ListNode* head, int val) {
    // edge case: remove first node(s)
    while (head != nullptr && head->val == val) {
        head = head->next;
    }
    if (head == nullptr) return head;

    ListNode* curr = head->next;
    ListNode* prev = head;
    while (curr != nullptr) {
        if (curr->val != val) {
            prev->next = curr;
            prev = prev->next;
        }
        curr = curr->next;
    }

    // edge case: remove last node(s)
    prev->next = curr;

    return head;
}

// USED SOLUTION
// cleaner solution that uses a sentinel node
ListNode* remove_elements2(ListNode* head, int val) {
    ListNode* sentinel = new ListNode(0);
    sentinel->next = head;

    ListNode* curr = head;
    ListNode* prev = sentinel;
    while (curr != nullptr) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }

        curr = curr->next;
    }

    ListNode* result = sentinel->next;
    delete sentinel;
    return result;
}

int main() {
    ListNode n7(6);
    ListNode n6(5, &n7);
    ListNode n5(4, &n6);
    ListNode n4(3, &n5);
    ListNode n3(6, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode* result = remove_elements2(&n1, 6);  // [1,2,3,4,5]
    ListNode* temp = result;
    while (temp != nullptr) {
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << '\n';

    result = remove_elements(nullptr, 1);  // []
    temp = result;
    while (temp != nullptr) {
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << '\n';

    n4 = ListNode(7);
    n3 = ListNode(7, &n4);
    n2 = ListNode(7, &n3);
    n1 = ListNode(7, &n2);
    result = remove_elements(&n1, 7);  // []
    temp = result;
    while (temp != nullptr) {
        cout << temp->val << ' ';
        temp = temp->next;
    }
    cout << '\n';
}
