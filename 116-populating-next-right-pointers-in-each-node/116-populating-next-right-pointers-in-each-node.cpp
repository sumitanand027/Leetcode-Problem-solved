/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if( root == NULL ) return root;
        queue <Node *> q;
        
        q.push( root );
        q.push( NULL );
        while( !q.empty() )
        {
            Node * cur = q.front();
            q.pop();
            
            if( cur &&  cur -> left )
                q.push( cur -> left );
            
            if( cur && cur -> right )
                q.push( cur -> right );
                
        
            if( cur == NULL ) {
                
                if( q.empty() ) break;
                q.push( NULL );
            }
            if( cur != NULL )
            cur -> next = q.front();
            
        }
        
        return root;
    }
};
