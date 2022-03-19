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
    
    void helper ( TreeNode * root , int minV , int maxV , int & ans )
    {
        if( root == NULL ) return;
        
        ans = max ( {ans , abs( root -> val - minV ) , abs( root -> val - maxV ) });
        
        helper( root -> left , min( minV , root -> val ) , max( maxV , root -> val ) , ans);
        helper( root -> right , min( minV , root -> val ) , max( maxV , root -> val ) , ans );
        
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        
        helper( root , root -> val , root -> val , ans );
        
        return ans;
    }
};