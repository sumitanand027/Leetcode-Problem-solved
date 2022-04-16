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
    
    int dfs( TreeNode * root , int &sum ) 
    {
        if( root == NULL ) return sum;
        
        int rightVal = dfs( root -> right , sum );
        root -> val += rightVal ;
        return dfs( root -> left , root -> val );
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs( root , sum );
        return root;
    }

};