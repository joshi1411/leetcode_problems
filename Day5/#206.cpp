/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next)
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* nextptr=NULL;
        while(head != NULL){
            ListNode* temp=(head->next);
            head->next=nextptr;
            nextptr=head;
            head=temp;
        }
        return nextptr;
    }
};