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
    
    bool helper( TreeNode * ta , TreeNode * tb ) {
        if( !ta && !tb ) return true;
        if( ta && !tb ) return false;
        if( !ta && tb ) return false;
        
        if( ta -> val != tb -> val ) return false;
        bool sa = helper( ta -> left , tb -> right );
        bool sb = helper( ta -> right , tb -> left );
        
        if( !sa || !sb ) return false;
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper( root -> left , root -> right );
    }
};