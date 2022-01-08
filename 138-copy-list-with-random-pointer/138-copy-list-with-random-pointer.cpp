/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head ) return NULL;
        
        vector< Node* > v;
        Node * it = head;
        unordered_map< Node * , Node * > m;
        Node * newHead ;
        while( it ) 
        {
            Node * newNode = new Node( it -> val );
            v.push_back( newNode );
            if( v.size() > 1 )
            {
                v[v.size()-2]-> next = newNode;
            }
            else{
                newHead = newNode;
            }
            m[ it ] = newNode;
            it = it -> next;
        }
        
        int i = 0;
        it = head;
        while( it ) {
            v[i]->random = m[it->random];
            it = it -> next;
            i++;
        }
        return newHead;
    }
};




