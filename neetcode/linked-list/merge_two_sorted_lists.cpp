/*
m = # of nodes in list1
n = # of nodes in list2
runtime: O(m+n)
space: O(1)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = new ListNode();
        ListNode* head = node;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val) {
                node->next = curr1;
                curr1 = curr1->next;
            } else {
                node->next = curr2;
                curr2 = curr2->next;
            }
            node = node->next;
        }
        if (curr1 != nullptr) node->next = curr1;
        if (curr2 != nullptr) node->next = curr2;
        return head->next;
    }
};

/*
NOT QUITE CORRECT (creates new nodes)
m = # of nodes in list1
n = # of nodes in list2
runtime: O(m+n)
space: O(m+n)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            return mergeTwoLists(new ListNode(list2->val, list1), list2->next);
        }
    }
};

/*
NOT QUITE CORRECT (creates new nodes)
m = # of nodes in list1
n = # of nodes in list2
runtime: O(m+n)
space: O(m+n)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            return new ListNode(list1->val, mergeTwoLists(list1->next, list2));
        } else {
            return new ListNode(list2->val, mergeTwoLists(list1, list2->next));
        }
    }
};

/*
USED SOLUTION
m = # of nodes in list1
n = # of nodes in list2
runtime: O(m+n)
space: O(m+n)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
