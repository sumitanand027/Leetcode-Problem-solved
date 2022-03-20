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
    
    void helper( TreeNode * root , int &ans , priority_queue<int> p )
    {
        if( root == NULL ) return;
        
        if( !p.empty() && p.top() <= root -> val ) {
            ans++;
        }
        if( p.empty() ) ans++;
        
        p.push( root -> val );
        
        helper( root -> left , ans , p );
        helper( root -> right , ans , p );
    }
    
    int goodNodes(TreeNode* root) {
        priority_queue< int > p;
        
        int ans = 0;
        
        helper( root , ans , p );
        
        return ans;
    }
};