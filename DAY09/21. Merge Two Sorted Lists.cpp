class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while(tempA && tempB){
            if(tempA->val <= tempB->val){
                ans->next = tempA;
                tempA = tempA->next;
            } else {
                ans->next = tempB;
                tempB = tempB->next;
            }
            ans = ans->next;  
        }
        if(tempA) ans->next = tempA;
        if(tempB) ans->next = tempB;

        return dummy->next;
    }
};
