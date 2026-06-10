class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while (l1 || l2) {
            int x = carry;

            if (l1) {
                x += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                x += l2->val;
                l2 = l2->next;
            }

            if (x >= 10) carry = x / 10;
            else carry = 0;

            ListNode* t = new ListNode(x % 10);
            curr->next = t;
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }

        return ans->next;
    }
};
