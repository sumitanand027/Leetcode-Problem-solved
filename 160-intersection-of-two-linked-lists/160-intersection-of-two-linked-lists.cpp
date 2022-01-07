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
    
    int ll_Diff( ListNode *l1, ListNode *l2 ) {
        int len1 = 0, len2 = 0;
        while( l1 || l2 ) 
        {
            if( l1 ) {
                len1++;
                l1 = l1 -> next;
            }
            if( l2 ) {
                len2++;
                l2 = l2 -> next;
            }
        }
        return len1 - len2;
    }
    
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2 ) {
        int diff = ll_Diff( l1 , l2 );
        if( diff < 0 )
        {
            while( diff != 0 ) {
                diff++;
                l2 = l2 -> next;
            }
        } 
        else 
        {
            while( diff != 0 ) {
                diff--;
                l1 = l1 -> next;
            }
        }
        
        while( l1 ) {
            if( l1 == l2 ) return l1;
            l2 = l2 -> next;
            l1 = l1 -> next;
        }
        return l1;
    }
};









