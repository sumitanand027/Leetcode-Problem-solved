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
    
    TreeNode * helper( vector<int> & p , int i , int j )
    {
        if( i > j ) 
        {
            return NULL;
        }
        
        TreeNode * curNode = new TreeNode ( p[i] );
        int k;
        for( k = i + 1 ; k <= j ; k++ )
        {
            if( p[k] > p[i] ) {
                break;
            }
        }
        curNode -> left = helper( p , i + 1 , k - 1 );
        curNode -> right = helper( p , k , j );
        return curNode;
    }
    
    TreeNode* bstFromPreorder(vector<int>& p ) {
        return helper( p , 0 , p.size() - 1 );
    }
};