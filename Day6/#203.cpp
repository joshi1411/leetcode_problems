"https://leetcode.com/problems/remove-linked-list-elements/"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur=head,*prev=nullptr;
        while(cur!=nullptr){
            if(cur->val==val){
                if(prev==nullptr){
                    head=head->next; // consider case of deleting values from first index,prev will be still null 
                    cur=cur->next;
                }else{
                    prev->next=cur->next;
                    cur=cur->next;
                }
            }else{
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};