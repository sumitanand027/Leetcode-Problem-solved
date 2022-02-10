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
    
    int helper( TreeNode * root, int &ans )
    {
        if( !root ) return INT_MIN;
        
        int l = helper( root -> left, ans );
        int r = helper( root -> right, ans );
        
        // ans = max( ans, l );
        // ans = max( ans, r );
        
        int resAns = root -> val;
        
        if ( l != INT_MIN && r != INT_MIN ) {
            ans = max( { ans , root -> val , root -> val + l , root -> val + r  });
            if( ans < resAns + l + r ) {
                ans = resAns + l + r;
                return max( l , r ) + resAns;
            }
            return max( { root -> val , root -> val + l , root -> val + r } );
        } 
        else if ( l != INT_MIN )
            resAns = max( resAns, root -> val + l );
        else if ( r != INT_MIN )
            resAns = max( resAns, root -> val + r );
      
        ans = max( ans, resAns );
        
        return resAns;   
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        helper( root, ans );
        
        return ans;
    }
};