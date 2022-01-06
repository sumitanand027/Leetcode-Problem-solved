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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode();
        ListNode * cur = head;
        int carry = 0;
        
        while( l1 && l2 )
        {
            int curVal = l1 -> val + l2 -> val + carry;
            ListNode * newNode = new ListNode( curVal % 10 );
            cur -> next = newNode;
            cur = newNode;
            if( curVal / 10 > 0 ) {
                carry = 1;
            } else {
                carry = 0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while( l1 ) {
            int curVal = l1 -> val + carry;
            ListNode * newNode = new ListNode( curVal % 10 );
            cur -> next = newNode;
            cur = newNode;
            if( curVal / 10 > 0 ) {
                carry = 1;
            } else {
                carry = 0;
            }
            l1 = l1 -> next;
        }
        while( l2 ) {
            int curVal = l2 -> val + carry;
            ListNode * newNode = new ListNode( curVal % 10 );
            cur -> next = newNode;
            cur = newNode;
            if( curVal / 10 > 0 ) {
                carry = 1;
            } else {
                carry = 0;
            }
            l2 = l2 -> next;
        }

        if( carry ) {
            ListNode * newNode = new ListNode( 1 );
            cur -> next = newNode;
        }
        return head -> next;
    }
};

