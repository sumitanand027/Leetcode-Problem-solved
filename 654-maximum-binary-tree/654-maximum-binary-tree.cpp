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
    
    
    int treeIndex( vector<int> &nums , int i , int j )
    {
        int mx = -1;
        int ind;
        
        for( ; i <= j ; i++ )
        {
            if( nums[i] > mx ) {
                ind = i;
                mx = nums[i];
            }
        }
        
        return ind;
    }
    
    TreeNode* helper( vector<int> &nums , int i , int j )
    {
        if( i > j ) return NULL;
        
        int mxEle = treeIndex ( nums , i , j );
        
        TreeNode * newNode = new TreeNode ( nums[mxEle] );
        
        newNode -> left = helper( nums , i , mxEle - 1 );
        newNode -> right = helper( nums , mxEle + 1 , j );
        
        return newNode;
    }
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper( nums ,  0 , nums.size() - 1 );
        
    }
};









