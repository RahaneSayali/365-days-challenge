class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if (head->val > 4) {
            head = new ListNode(0, head);
        }
        
        ListNode* temp = head;
        while (temp != nullptr) {
            // Double the value and take modulo 10 to handle carry
            temp->val = (temp->val * 2) % 10;
            
            // If the next node exists and its value is greater than 4, 
            // increment current node's value
            if (temp->next != nullptr && temp->next->val > 4) {
                temp->val++;
            }
            
            temp = temp->next; // Move to the next node
        }
        
        return head;
    }
};