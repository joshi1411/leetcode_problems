"https://leetcode.com/problems/palindrome-linked-list/"
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode* nxt=nullptr;
        while(head!=nullptr){
            ListNode* tp=head->next;
            head->next=nxt;
            nxt=head;
            head=tp;
        }
        return nxt;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* dumMid=reverse(slow); // or you can check while reversing the half list itselt
        bool ok=true;
        ListNode* temp=head;
        while(temp!=nullptr and dumMid!=nullptr){
            if(temp->val != dumMid->val)ok=false;
            temp=temp->next;
            dumMid=dumMid->next;
        }
        return ok;
    }
};