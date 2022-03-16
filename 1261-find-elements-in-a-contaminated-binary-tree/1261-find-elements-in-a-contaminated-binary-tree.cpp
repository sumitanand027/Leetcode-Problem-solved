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
class FindElements {
public:
    TreeNode * parent;
    
    void helper( TreeNode * root )
    {
        if( root == NULL ) return;
        
        if( root -> left )
            root -> left -> val = root -> val * 2 + 1;
        
        if( root -> right )
            root -> right -> val = root -> val * 2 + 2;
        
        helper( root -> left );
        helper( root -> right );
    }
    
    FindElements(TreeNode* root) {
        parent = root;
        parent -> val = 0;
        helper ( root );
    }
    
    bool helper_find( TreeNode * root , int tar ) 
    {
        if( root == NULL ) return false;
        
        if( root -> val == tar )
            return true;
        
        if ( helper_find( root -> left , tar ) )
            return true;
        
        return helper_find( root -> right , tar );
        
    }
    
    bool find(int target) {
        return helper_find( parent , target );
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */