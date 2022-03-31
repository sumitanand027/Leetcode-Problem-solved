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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root == NULL )
            return NULL;
        
        else if( root -> val == key ) {
            if( root -> left ){
                TreeNode *it = root -> right;
                if( !it ) return root -> left;
                while( it -> left ) it = it -> left;
                it -> left = root -> left;
                return root -> right;
            }
            else if( root -> right ){
                return root -> right;
            }
    
              
            return NULL;
        }
        
        root -> left = deleteNode ( root -> left , key );
        root -> right = deleteNode( root -> right , key );
        
        return root;
    }
};