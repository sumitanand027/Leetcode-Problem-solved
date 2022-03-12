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
    
    void inorder ( TreeNode * cur , vector<TreeNode *> &ind )  {
        if( !cur ) return;
        
        inorder ( cur -> left , ind );
        ind.push_back ( cur  );
        inorder ( cur -> right , ind );       
    }
    
    TreeNode *  helper( vector <TreeNode *> &ind , int i , int j )
    {
        if( i > j ) return NULL;
        
        int mid = ( i + j ) / 2;
        
        ind[ mid ] -> left = helper( ind , i , mid - 1 );
        ind[ mid ] -> right = helper( ind , mid + 1 , j );
        
        return ind[mid];
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> ind;
        inorder( root , ind );
        
        return helper( ind , 0 , ind.size() - 1 );
    }
};