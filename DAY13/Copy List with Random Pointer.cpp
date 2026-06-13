class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node* dummy = new Node(0);
        Node* ans = dummy;
        Node* temp = head;

        // Step 1: Create copy of next pointers
        while (temp) {
            Node* a = new Node(temp->val);
            ans->next = a;
            ans = ans->next;
            temp = temp->next;
        }

        unordered_map<Node*, Node*> m;

        Node* c = head;
        Node* b = dummy->next;  
        while (c && b) {
            m[c] = b;
            c = c->next;
            b = b->next;
        }

        // Step 3: Assign random pointers
        c = head;
        b = dummy->next;

        while (c) {
            if (c->random) {
                b->random = m[c->random];
            }
            c = c->next;
            b = b->next;
        }

        return dummy->next;
    }
};
