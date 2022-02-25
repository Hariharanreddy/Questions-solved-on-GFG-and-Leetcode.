/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
bool detectLoop(ListNode* head, ListNode* &slow, ListNode* &fast) {
    

    while(fast != NULL && fast -> next != NULL)
    {
        
        fast = fast -> next -> next;
        slow = slow -> next;
        
        //cycle is present
        if(slow == fast)
        {
            return true;
        }
    
    }
    
    return false;

}
    
ListNode *detectCycle(ListNode *head) {
    
    //for empty list
    if(head == NULL)
    {
        return NULL;
    }

    
    ListNode *slow = head;
    ListNode *fast = head;
        
    if(detectLoop(head, slow, fast))
    {
        slow = head;
        
        while(slow != fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
    }
    else
    {
        return NULL;
    }
        
    }
};