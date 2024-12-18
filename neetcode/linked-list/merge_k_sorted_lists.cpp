/*
n == total # of nodes in all lists
runtime: O(n*lg(n))
space: O(n)
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<>> pq;

        for (int i = 0; i < n; i++) {
            ListNode* curr = lists[i];
            while (curr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!pq.empty()) {
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }
        return dummy->next;
    }
};
