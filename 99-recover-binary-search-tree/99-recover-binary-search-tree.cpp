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
    
    TreeNode *first;
    TreeNode *last;
    TreeNode *pre;
    TreeNode *middle;
    
    void inorder( TreeNode *root )
    {
        if( root == NULL )
            return;
        
        inorder( root -> left );
        if( pre != NULL && root -> val < pre -> val )
        {
            if( first == NULL )
            {
                first = pre;
                middle = root;
            } else 
            {
                last = root;
            }
        }
        pre = root;
        inorder( root -> right );
    }
    
    
    void recoverTree(TreeNode* root) {
        first = last = pre = middle = NULL;
        
        inorder( root );
        if( first && last ) swap( first -> val , last -> val );
        else if( first && middle ) swap( first -> val , middle -> val );
    }
};