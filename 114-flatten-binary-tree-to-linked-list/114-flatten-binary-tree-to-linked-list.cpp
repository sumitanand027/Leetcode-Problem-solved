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
    
    TreeNode * helper( TreeNode * cur ) {
        if( cur == NULL ) return NULL;
        
        TreeNode * last = cur;
        TreeNode * temp = cur -> right;
        
        if( cur -> left ) 
        {
            last = helper( cur -> left );
            cur -> right =  cur -> left;
            cur -> left = NULL;
            last -> right = temp;
        }
        TreeNode * Rlast = helper( temp );
        if( Rlast ) {
            last = Rlast;
        }
        return last;
    }
    
    void flatten(TreeNode* root) {
        helper( root );
    } 
    
};








