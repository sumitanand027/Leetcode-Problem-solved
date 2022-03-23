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
    
    
    TreeNode * adjBST( TreeNode * cur )
    {
        if( cur -> right == NULL && cur -> left == NULL )
            return NULL;
        
        else if( cur -> left && cur -> right == NULL )
            return cur -> left;
        
        else if( cur -> left == NULL && cur -> right )
            return cur -> right;
        
        TreeNode * it = cur -> right;
        
        while( it -> left != NULL ) {
            it = it -> left;
        } 
        
        it -> left = cur -> left;
        return cur -> right;
    }
    
    TreeNode * dfs( TreeNode * cur , int l , int h )
    {
        if( cur == NULL )
            return NULL;
        
//         if( cur -> val < l || cur -> val > h ) {
//             // TreeNode * newCur = adjBST( cur );
//             // if( newCur == NULL ) return NULL;
            
//             cur = newCur;
//         }
        
        if( cur -> val < l )
        {
            if( cur -> right )
                cur = cur -> right;
            else 
                return NULL;
        }
        if( cur -> val > h ) {
            if( cur -> left )
                cur = cur ->left;
            else 
                return NULL;
        }
        
        cur -> left = dfs( cur -> left , l , h );
        cur -> right = dfs( cur -> right , l , h );
        
        if( cur -> val < l )
        {
            // if( cur -> right )
            //     cur = cur -> right;
            // else 
                return cur -> right;
        }
        if( cur -> val > h ) {
            // if( cur -> left )
            //     cur = cur ->left;
            // else 
                return cur -> left;
        }
        
        return cur;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs( root , low , high );
    }
};








