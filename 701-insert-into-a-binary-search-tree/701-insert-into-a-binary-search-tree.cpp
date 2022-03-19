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
    
    void insertVal( TreeNode * root , int val ){
        if( root == NULL ) return;
        
        if( root -> val > val ) 
        {
            if( root -> left == NULL ) 
            {
                TreeNode * newNode = new TreeNode ( val );
                root -> left = newNode; 
            } else {
                insertVal ( root -> left , val );
            }
        } 
        else {
            if( root -> right == NULL ) 
            {
                TreeNode * newNode = new TreeNode ( val );
                root -> right = newNode; 
            } else {
                insertVal ( root -> right , val );
            }
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if( root == NULL ) {
             TreeNode * newNode = new TreeNode ( val );
            return newNode;
        }
        insertVal( root , val );
        return root;
    }
};