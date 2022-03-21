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
    
    int helper( TreeNode * root , int k , int cnt , int & ans )
    {
        if( root == NULL ) return 0;
        
        int l = helper( root -> left , k , cnt , ans );
        
        int curRank = cnt + l + 1;
        
        if( curRank == k ) {
            ans = root -> val;
            cout << ans;
            return curRank;
        }
        
        int r = helper( root -> right , k , curRank , ans );
        
        return l + r + 1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        
        helper( root , k , 0 , ans );
        
        return ans;
    }
};