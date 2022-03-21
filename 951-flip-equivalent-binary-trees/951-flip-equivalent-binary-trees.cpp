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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( root1 == NULL && root2 == NULL ) return 1;
        else if( root1 == NULL && root2 ) return 0;
        else if( root1 && root2 == NULL ) return 0;
        
        if( root1 -> val != root2 -> val ) return 0;
        
        bool ans1 = flipEquiv( root1 -> left , root2 -> right );
        bool ans2 = flipEquiv( root1 -> right , root2 -> left );
        
        bool ans3 = flipEquiv( root1 -> left , root2 -> left );
        bool ans4 = flipEquiv( root1 -> right , root2 -> right );
        
        if( ans1 && ans2 ) {
            return 1;
        }
        if( ans3 && ans4 ) {
            return 1;
        }
        return 0;
    }
};



