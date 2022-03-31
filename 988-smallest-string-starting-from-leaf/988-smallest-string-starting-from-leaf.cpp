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
    
    string ans = "~";
    
    void helper( TreeNode * root , string s )
    {
        if( root == NULL )
            return;
        
        string pas;
        pas += 'a' + root -> val;
        pas += s;
        
        
        if( root -> left == NULL && root -> right == NULL ) {
            ans = min( ans , pas );
            return;
        }
        
        
        helper( root -> left , pas );
        helper( root -> right , pas );
        
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        helper( root , "" );
        return ans;
    }
};