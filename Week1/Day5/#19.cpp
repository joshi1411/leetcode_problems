"https://leetcode.com/problems/remove-nth-node-from-end-of-list/"
//actual required solution. 
"https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/9094/Here-is-my-solution-in-C-(one-pass-2-pointers)-with-comments"

class Solution {//naive approach 
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=1;
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *curr=head;
        ListNode *point=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            m++;
        }
        int l=(m-n);
        if(l==0)
            return head->next;
        while(--l){
            point=point->next;
        }
        point->next=point->next->next;
        return head;
    }
};
//wtf solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0;
        ListNode* temp=head;
        while(head){
            head=head->next;
            m++;
        }
        if(m==n)return temp->next; //edge case
        ListNode* pos=temp + (m-n-1)*sizeof(ListNode)/sizeof(ListNode*); //got this by hit&trial
        pos->next=pos->next->next;
        return temp;
    }
};