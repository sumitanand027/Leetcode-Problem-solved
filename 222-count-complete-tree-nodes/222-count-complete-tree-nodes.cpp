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
    int countNodes(TreeNode* root) {
        if( root == NULL )
            return 0;
        
        int  l = 0 , r = 0;
        TreeNode * it = root -> left;
        while( it ) {
            it = it -> left;
            l++;
        }
        it = root -> right;
        while( it ) {
            it = it -> right;
            r++;
        }
        if( l == r ) {
            return pow( 2 , l + 1 ) - 1;
        }
        
        return 1 + countNodes( root -> left ) + countNodes( root -> right );
    }
};