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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > ans;
        if( !root ) return ans;
        
        queue< TreeNode * > q;
        q.push( root );
        q.push( NULL );    
        
        vector<int> level;
        while( !q.empty() )
        {
            TreeNode * curNode = q.front();
            if( curNode )
                level.push_back( curNode -> val );
            q.pop();
            
            if( curNode && curNode -> left )
                q.push( curNode -> left );
            
            if( curNode && curNode -> right )
                q.push( curNode -> right );
            
            if( curNode == NULL )
            {
                ans.push_back( level );
                level.clear();
                if( q.empty() )
                    break;
                q.push( NULL );
            }
            
        }
        return ans;
    }
};



