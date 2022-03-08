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
    bool hasCycle(ListNode *head) {
        ListNode * l = head;
        ListNode * f = head;
        
        if( !l || !l -> next ) return 0;
        if( l -> next == l ) return 1;
        
        while( f && l ) {
           if( f -> next && f -> next -> next )
               f = f -> next -> next;
            else return 0;
            l = l -> next;
            if( f == l ) return 1;
        }
        return 0;
    }
};