/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
        queue < TreeNode *> q;
        q.push( root );
        
        int sum = 0;
        
        while( !q.empty() )
        {
            TreeNode * cur = q.front();
            q.pop();
            
            cout << cur -> val << endl;
            if( cur -> left )
            {
                q.push( cur -> left );
                if( cur -> val % 2 == 0 ) 
                {
                    if( cur -> left -> left ) {
                        sum += cur -> left -> left -> val; 
                    }
                    if( cur -> left -> right ) {
                        sum += cur -> left -> right -> val;
                    }
                }
            }
            
            if( cur -> right )
            {
                q.push( cur -> right );
                if( cur -> val % 2 == 0 ) 
                {
                    if( cur -> right -> left ) {
                        sum += cur -> right -> left -> val; 
                    }
                    if( cur -> right -> right ) {
                        sum += cur -> right -> right -> val;
                    }
                }
            }
        }
        return sum;
    }
};
