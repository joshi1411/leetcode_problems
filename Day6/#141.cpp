"https://leetcode.com/problems/linked-list-cycle/submissions/"
  class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while (slow && fast && fast->next) { //to stop when fast reaches null
        slow = slow->next; 
        fast = fast->next->next; 
            if (slow == fast) { //finds the intersection point
                return true;
            } 
        } 
      return false;  
    }
};