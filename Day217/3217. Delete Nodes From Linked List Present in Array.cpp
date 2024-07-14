/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Create a dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        
        // Use two pointers to traverse the list
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (numSet.find(curr->val) != numSet.end()) {
                // Remove the node
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        
        return dummy.next;
    }
};