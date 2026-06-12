class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=NULL;
        int ans=-1;
        while(fast && fast->next){            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                ans=0;   
                break; 
            }        
        }
        if(ans==0){
            slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }            
        
        return temp;        
    }
};
