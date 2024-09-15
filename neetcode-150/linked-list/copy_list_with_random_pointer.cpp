/*
n == # of nodes
runtime: O(n)
space: O(n)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node{0};
        Node* dummy_curr = dummy;

        unordered_map<Node*, Node*> clone_map;

        Node* curr = head;
        while (curr) {
            if (!clone_map.count(curr)) {
                if (curr) {
                    clone_map[curr] = new Node{curr->val};
                } else {
                    clone_map[curr] = nullptr;
                }
            }

            if (!clone_map.count(curr->random)) {
                if (curr->random) {
                    clone_map[curr->random] = new Node{curr->random->val};
                } else {
                    clone_map[curr->random] = nullptr;
                }
            }

            Node* node = clone_map[curr];
            Node* random = clone_map[curr->random];
            node->random = random;

            dummy_curr->next = node;
            dummy_curr = dummy_curr->next;

            curr = curr->next;
        }
        return dummy->next;
    }
};
