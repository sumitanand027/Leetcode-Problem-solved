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
    
    TreeNode * helper( vector<int> &nums, int i , int j )
    {
        if( i > j ){
            return NULL;
        }
        
        int m = ( i + j ) / 2;
        TreeNode * curNode = new TreeNode ( nums[m] );
        
        TreeNode * l = helper( nums, i , m - 1 );
        TreeNode * r = helper( nums, m + 1 , j );
        
        curNode -> left = l;
        curNode -> right = r;
        return curNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper( nums , 0 , nums.size() - 1 );
    }
};





