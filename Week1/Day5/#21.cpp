"https://leetcode.com/problems/merge-two-sorted-lists/submissions/"
class Solution {//recursion solution.. noice! 
public:
    //recursive solution
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;  
        if (l1 == NULL)  
            return(l2);  
        else if (l2 == NULL)  
            return(l1);  
        if (l1->val <= l2->val){  
            result = l1;  
            result->next = mergeTwoLists(l1->next, l2);  
        }else{  
            result = l2;  
            result->next = mergeTwoLists(l1, l2->next);  
        }  
        return(result);  
    }
};
class Solution {
public:
    //iterative solution
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* insPos=nullptr;
        ListNode* start=nullptr; //head of new merged list
        while(l1!=nullptr || l2!=nullptr){
            ListNode* temp=new ListNode();
            if(l1==nullptr){
                temp->val=l2->val;
                l2=l2->next;
            }
            else if(l2==nullptr){
                temp->val=l1->val;
                l1=l1->next;
            }
            else{
                if(l1->val < l2->val){
                    temp->val=l1->val;
                    l1=l1->next;
                }else{
                    temp->val=l2->val;
                    l2=l2->next;
                }
            }
            temp->next=nullptr;
            if(insPos==nullptr){
                insPos=temp;
                start=insPos;
            }else{
                insPos->next=temp;
                insPos=temp;
            }
        }
        return start;
    }
};