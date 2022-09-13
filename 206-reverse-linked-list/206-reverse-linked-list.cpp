/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head , ListNode* pre = NULL ) {
        if( head == NULL )
            return NULL;
        
        
        ListNode *headR = reverseList ( head -> next , head );
        
        if( head -> next )
            head -> next = head;
        head -> next = pre;
        if( headR )
            return headR;
        return head;
    }
};