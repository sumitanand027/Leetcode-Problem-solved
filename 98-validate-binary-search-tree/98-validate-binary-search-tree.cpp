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
    
    bool isValidBST( TreeNode * root , long long int HRange , long long int LRange ) {
        if( root == NULL ) return true;
        
        if( root -> val >= HRange || root -> val <= LRange )
            return false;
        
        if ( !isValidBST( root -> left , root -> val , LRange ) ) return false;
        
        return isValidBST( root -> right , HRange , root -> val );
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST( root , 1e12 , -1e12 );
    }
};




