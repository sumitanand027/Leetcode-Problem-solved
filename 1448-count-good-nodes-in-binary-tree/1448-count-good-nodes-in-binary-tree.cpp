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
    
    void helper( TreeNode * root , int &ans , multiset< int , greater<int> > &p )
    {
        if( root == NULL ) return;
        
        if( !p.empty() && *p.begin() <= root -> val ) {
            ans++;
        }
        if( p.empty() ) ans++;
        
        p.insert( root -> val );
        
        helper( root -> left , ans , p );
        helper( root -> right , ans , p );
        
        auto it = p.find( root -> val );
        p.erase( it );
    }
    
    int goodNodes(TreeNode* root) {
        multiset< int , greater<int> > p;
        
        int ans = 0;
        
        helper( root , ans , p );
        
        return ans;
    }
};