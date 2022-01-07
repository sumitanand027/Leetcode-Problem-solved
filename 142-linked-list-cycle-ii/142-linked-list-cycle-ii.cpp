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
    ListNode *detectCycle(ListNode *head) {
        if( !head || !head -> next ) return NULL;
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while( fast && fast -> next ) 
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if( fast == slow ) break;
        }
        
        if( slow != fast ) return NULL;
        // cout << slow -> val << endl;;
        // cout << fast -> val;
        slow = head;
        while( slow != fast ) 
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        // cout << slow -> val;
        return slow;
    }
};






