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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * p = head;
        int times = k;
        while( times > 1 ) {
            p = p -> next;
            times--;
        }
        
        ListNode * left = p;
        ListNode * q = head;
        
        while( p -> next ) {
            q = q -> next;
            p = p -> next;
        }
        
        int temp = q -> val;
        q -> val = left -> val;
        left -> val = temp;
        
        return head;
    }
};