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
    
    pair< bool, int> checkBal( TreeNode * curNode ) 
    {
        if( curNode == NULL ) return { true, 0 };
        
        pair< bool, int> left = checkBal( curNode -> left );
        pair< bool, int> right = checkBal( curNode -> right );
        
        int height = max( left.second , right.second ) + 1;
        bool res = true;
        if( abs( left.second - right.second ) > 1 ) {
            res = false;
        }
        if( !res || !left.first || !right.first )
            return { false, height };
        
        return { true, height };
    }
    
    bool isBalanced(TreeNode* root) {
        pair< bool, int> ans = checkBal( root );
        
        return ans.first;
    }
};