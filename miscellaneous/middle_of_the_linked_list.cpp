/*
1 -> 2 -> 3 -> 4 -> 5 -> 6
1 2
2 4
3 6
done

1 -> 2 -> 3 -> 4 -> 5
1 2
2 4
3 done

n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
        }
        return slow;
    }
};

/*
1 -> 2 -> 3 -> 4 -> 5 -> 6
1 1
2 3
3 5
4 null
done

1 -> 2 -> 3 -> 4 -> 5
1 1
2 3
3 5
done

USED SOLUTION
n == # of nodes
runtime: O(n)
space: O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
