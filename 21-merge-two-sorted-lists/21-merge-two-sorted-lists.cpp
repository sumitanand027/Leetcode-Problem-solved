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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * l1 , *l2 , *cur;
        ListNode * head;
        if( !list1 )
            return list2;
        if( !list2)
            return list1;
        
        if( list1 -> val < list2 -> val )
        {
            cur = list1;
            head = list1;
            l1 = list1 -> next;
            l2 = list2;
        }
        else
        {
            cur = list2;
            head = list2;
            l1 = list1;
            l2 = list2 -> next;
        }
        
        while( l1 && l2 ) 
        {
              if( l1 -> val < l2 -> val )
              {
                  cur -> next = l1;
                  cur = l1; 
                  l1 = l1 -> next; 
              } else {
                  cur -> next = l2;
                  cur = l2;   
                  l2 = l2 -> next; 
              }
        }
        while( l1 ) {
            cur -> next = l1;
            cur = l1;
            l1 = l1 -> next;
        }
        while( l2 ) {
            cur -> next = l2;
            cur = l2;
            l2 = l2 -> next;
        }
        cur -> next = NULL;
        return head;
    }
};
    
    
    
    
    
    
    
    
    
    