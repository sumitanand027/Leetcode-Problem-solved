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
    
    bool helper( TreeNode * pre , TreeNode * cur )
    {
        if( cur == NULL ) return false;
        
        bool ans1 = helper( cur , cur -> left );
        bool ans2 = helper( cur , cur -> right );
        
        bool ans = ans1 || ans2;
        if( cur -> val == 1 ) ans = 1;
        
        
        if( !ans ) 
        {
            if( pre ) 
            {
                if( pre -> left && pre -> left == cur )
                    pre -> left = NULL;
                
                if( pre -> right && pre -> right == cur )
                    pre -> right = NULL;
            }
        }
        return ans;
    }
    
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        bool ans = helper( NULL , root );
        
        if( !ans )
            return NULL;
        return root;
    }
};