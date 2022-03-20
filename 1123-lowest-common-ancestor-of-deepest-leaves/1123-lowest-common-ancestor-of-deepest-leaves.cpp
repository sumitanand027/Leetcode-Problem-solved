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
    
    void calDep( TreeNode * cur , int &dep , int &cnt , int curDep )
    {
        if( cur == NULL ) return;
        
        if( curDep == dep ) {
            cnt++;
        }
        if( curDep > dep ) {
            dep = curDep;
            cnt = 1;
        }
        
        calDep( cur -> left , dep , cnt , curDep + 1 );
        calDep( cur -> right , dep , cnt , curDep + 1 );
        
    }
    
    int lca( TreeNode * root , int &dep , int &cnt , TreeNode * &subTree , int curDep )
    {
        if( root == NULL )
            return 0;
        
        if( curDep == dep ) {
            if( cnt == 1 ) {
                subTree = root;
            }
            return 1;
        }
        
        int l = lca( root -> left , dep , cnt , subTree , curDep + 1 );
        int r = lca( root -> right , dep , cnt , subTree , curDep + 1 );
        
        if( subTree ) return l + r;
        if( l + r == cnt ) subTree = root;
        return l + r;
    }
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int dep = 0;
        int cnt = 0;
        
        calDep ( root , dep , cnt , 0 );

        TreeNode * subTree = NULL;
        lca( root , dep , cnt , subTree , 0 );
        
        return subTree;
    }
};