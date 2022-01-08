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
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || !head -> next ) return head;
        
        int len = 0;
        ListNode * cur = head;
        
        while( cur != NULL )
        {
            len++;
            cur = cur -> next;
        }
        
        int shift = k % len;
        if( shift == 0 )
            return head;
        
        
        ListNode * dummy = new ListNode ( -1 ); 
        dummy -> next = head;
        ListNode * slow = dummy;
        ListNode * fast = head;
        while( shift > 1 ) {
            fast = fast -> next;
            shift--;
        }
        
        while( fast -> next ) {
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = head;
        head = slow -> next;
        slow -> next = NULL;
        return head;
    }
};


