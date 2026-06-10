class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        temp=head;
        if(len==n) return head->next;
        for(int i=1;i<len-n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;        
    }
};
