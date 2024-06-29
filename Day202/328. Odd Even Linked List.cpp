class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; //edge case
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=head->next; //just to remember

        while(even!=NULL && even->next !=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        } 
        odd->next=evenHead;
        return head;
    }
};