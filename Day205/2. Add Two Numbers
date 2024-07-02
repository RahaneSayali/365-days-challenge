class Solution {
public:
   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

                        // Create a dummy node to simplify code and avoid special cases

        ListNode* dummynode = new ListNode(-1);

                    // Pointer 'curr' is used to traverse and build the result linked list

        ListNode* curr = dummynode;

                   // Pointers to traverse the input linked lists 'l1' and 'l2'
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

                  // Variable to store the carry when adding digits
        int carry = 0;

                      // Loop until both linked lists are exhausted
        while (temp1 != nullptr || temp2 != nullptr) {
                         // Initialize 'sum' with the carry from the previous iteration
            int sum = carry; 

                     // If there are remaining digits in 'l1', add the digit to 'sum'
            if (temp1) sum += temp1->val;

                       // If there are remaining digits in 'l2', add the digit to 'sum'
            if (temp2) sum += temp2->val;

                       // Create a new node with the value being the last digit of 'sum'
            ListNode* newNode = new ListNode(sum % 10);
                         // Update 'carry' with the tens digit of 'sum'
            carry = sum / 10;

                           // Link the new node to the result linked list
            curr->next = newNode;
                          // Move 'curr' to the newly added node
            curr = curr->next;

                          // Move pointers to the next nodes in 'l1' and 'l2' if there are remaining nodes
            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

                        // If there is a remaining carry after the loop, create a new node with the carry
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

                       // Return the head of the result linked list (next of the dummy node)
        return dummynode->next;
    }
};