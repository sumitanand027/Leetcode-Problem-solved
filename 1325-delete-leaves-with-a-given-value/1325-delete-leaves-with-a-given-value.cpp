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
    
    void helper( TreeNode * pre , TreeNode * cur , int tar )
    {
        if( cur == NULL ) return;
        
        // if( !cur -> left && !cur -> right && cur -> val == tar ) 
        // {
        //     if( pre ) {
        //         if( pre -> left && pre -> left -> val == tar )
        //         {
        //             pre -> left = NULL;
        //         } else {
        //              pre -> right = NULL;
        //         }
        //     }
        // }
    
        helper ( cur , cur -> left , tar );
        helper( cur , cur -> right , tar );
        
        if( !cur -> left && !cur -> right && cur -> val == tar ) 
        {
            if( pre ) {
                if( pre -> left && pre -> left == cur )
                {
                    pre -> left = NULL;
                } else {
                     pre -> right = NULL;
                }
            }
        }
        
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        helper( NULL , root , target );
        if( root -> val == target && !root -> left && !root -> right )
            return NULL;
        return root;
    }
};