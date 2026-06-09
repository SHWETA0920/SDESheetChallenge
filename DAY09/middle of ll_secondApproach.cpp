class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp =head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int n=len/2;
        ListNode* ans=head;       
            while(n--){
                ans=ans->next;                
            }
            return ans;        
    }
};
