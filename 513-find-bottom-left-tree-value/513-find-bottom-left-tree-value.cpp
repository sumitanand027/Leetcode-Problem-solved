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
    
    void calDepth( TreeNode * root, int curDepth , int & depth )
    {
        if( root == NULL ) return;
        
        depth = max( curDepth, depth );
        
        calDepth( root -> left, curDepth + 1 , depth );
        calDepth( root -> right, curDepth + 1, depth );
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        
        calDepth( root, 1 , depth );
        
        if( depth == 1 ) return root -> val;
        
        int curDepth = 0;
        queue<TreeNode *> q;
        q.push( root );
        q.push( NULL );
        
        while( !q.empty() )
        {
            TreeNode * cur = q.front();
            q.pop();
            
            if( cur -> left ) 
                q.push( cur -> left );
            
            if( cur -> right )
                q.push( cur -> right );
            
            if( q.front() == NULL ) {
                q.pop();
                curDepth++;
                if( q.empty() ) break;
                q.push( NULL );
            }
      
            if( curDepth == depth - 1 )
                return q.front() -> val;
        }
        return 0;
    }
};



