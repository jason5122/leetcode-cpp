#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// n == total # of nodes in list1 and list2
// runtime: O(n)
// space: O(n)
ListNode* merge_two_lists(ListNode* list1, ListNode* list2) {
    ListNode* sentinel = new ListNode(0);
    ListNode* head = sentinel;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            head->next = list1;
            list1 = list1->next;
        } else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }

    // only one list is non-empty at this point

    while (list1 != nullptr) {
        head->next = list1;
        list1 = list1->next;
        head = head->next;
    }
    while (list2 != nullptr) {
        head->next = list2;
        list2 = list2->next;
        head = head->next;
    }

    ListNode* result = sentinel->next;
    delete sentinel;
    return result;
}

// USED SOLUTION
// n == total # of nodes in list1 and list2
// runtime: O(n)
// space: O(n)
ListNode* merge_two_lists2(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val <= list2->val) {
        list1->next = merge_two_lists2(list1->next, list2);
        return list1;
    } else {
        list2->next = merge_two_lists2(list1, list2->next);
        return list2;
    }
}

int main() {
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* result = merge_two_lists2(list1, list2);  // [1,1,2,3,4,4]
    for (ListNode* temp = result; temp != nullptr; temp = temp->next) {
        cout << temp->val << ' ';
    }
    cout << '\n';

    list1 = nullptr;
    list2 = nullptr;
    result = merge_two_lists2(list1, list2);  // []
    for (ListNode* temp = result; temp != nullptr; temp = temp->next) {
        cout << temp->val << ' ';
    }
    cout << '\n';

    list1 = nullptr;
    list2 = new ListNode(0);
    result = merge_two_lists2(list1, list2);  // [0]
    for (ListNode* temp = result; temp != nullptr; temp = temp->next) {
        cout << temp->val << ' ';
    }
    cout << '\n';
}
