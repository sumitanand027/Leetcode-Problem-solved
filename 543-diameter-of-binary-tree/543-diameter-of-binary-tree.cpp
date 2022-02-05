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
    
    int dfs( TreeNode * cur, int & diameter ) 
    {
        if( cur == NULL ) return 0;
        
        int left = dfs( cur -> left, diameter );
        int right = dfs( cur -> right, diameter );
        
        diameter = max( left + right + 1 , diameter );
        
        return (max( left , right ) + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        dfs( root, diameter );
        
        return diameter - 1;
    }
};