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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode ( 0 );
        dummy -> next = head;
        ListNode * cur = NULL;
        ListNode * prev = NULL;
        ListNode * before = dummy;
        ListNode * after = head;
        ListNode * nxt = NULL;
        
        while( true )
        {
            ListNode * cursor = after;
            for( int i = 0; i < k ; i++ ) {
                if( cursor == NULL ) return dummy -> next;
                cursor = cursor -> next;
            }
            
            cur = after;
            prev = before;
            for( int i = 0; i < k ; i++ ) {
                nxt = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = nxt;
            }            
            after -> next = cur;
            before -> next = prev;
            before = after;
            after = cur;
        }
        return dummy;
    }
};
