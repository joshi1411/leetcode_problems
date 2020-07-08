"https://leetcode.com/problems/add-two-numbers/" //iterative solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=nullptr;
        ListNode* start=nullptr;
        int c=0;
        while(l1!=nullptr || l2!=nullptr || c!=0){
            int x=c;
            if(l1!=nullptr){
                x+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                x+=l2->val;
                l2=l2->next;
            }
            c=x/10;
            x%=10;
            ListNode *ptr=new ListNode(x);
            if(head==nullptr){
                head=ptr;
                start=head;
            }else{
                head->next=ptr;
                head=head->next;
            }
        }
        return start;        
    }
};