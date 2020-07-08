"https://leetcode.com/problems/linked-list-cycle-ii/"

//actual tricky method,which is the same as done in duplicate number(entrance finding using floyd hare and tortoise)
class Solution { //floyd cycle
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *tort = head, *hare = head;
        bool cycle=false;
        while(hare!=nullptr && tort!=nullptr && tort->next != nullptr){
            hare=hare->next;
            tort=tort->next->next;
            if(tort==hare){
                cycle = true;
                break;
            }
        }
        if(cycle){
            while(head!=tort){
                head=head->next;
                tort=tort->next;
            }
            return head;
        }else return nullptr;
    }
};

//naive approach using set/extra memory
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set <ListNode*> s; 
        while(head)
        {
            if(s.find(head)==s.end())
                s.insert(head);
            else
                return head;
            head=head->next;
        }        
        return head;
        
    }
};