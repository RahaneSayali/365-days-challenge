class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head; 
        ListNode* fast=head;
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow->next;
        slow->next=slow->next->next;
        delete(middle);
        return head;
    }
};