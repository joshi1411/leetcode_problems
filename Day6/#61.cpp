"https://leetcode.com/problems/rotate-list/submissions/"

class Solution {//naive approach
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr=head;
        ListNode *temp=head;
        ListNode *tail=head;
        int len=0;u8
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            len++;
        }
        if(k==0||head==NULL)
            return head;
        k=k%len;
        k=len-k;
        while(--len)
            temp=temp->next;
        temp->next=head;
        while(--k)
        {
            tail=tail->next;
            head=head->next;
        }
        head=head->next;
        tail->next=NULL;
        return head;
    }
};