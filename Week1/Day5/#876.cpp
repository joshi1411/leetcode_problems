"https://leetcode.com/problems/middle-of-the-linked-list/submissions/"
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL)
            return NULL;
        int n=1;
        ListNode*curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            n++;

        }
        //cout<<n<<" ";
        n=n/2+1;
        while(--n)
            head=head->next;
        return head;
        
    }
};
//preferred solution 
//initialise 2 pointers with head , jump fast one by 2 steps slow one by 1 next ..
//when fast one reaches null ,slow one would be at middle but check if there are 2 middle , just jump slow one to next
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *tort=head,*hare=head;
        while(tort->next!=nullptr && tort->next->next!=nullptr){ //discussion channel has better implementation
            tort=tort->next->next;
            hare=hare->next;
        }
        if(tort->next!=nullptr)hare=hare->next;
        return hare;
    }
};