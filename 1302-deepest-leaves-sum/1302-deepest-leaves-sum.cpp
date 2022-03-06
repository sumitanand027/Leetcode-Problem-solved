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
    
    int depth( TreeNode * cur )
    {
        if( cur == NULL ) return 0;
        
        int l = depth( cur -> left );
        int r = depth( cur -> right );
        
        return max( l , r ) + 1;
    }
    
    void sum( TreeNode * cur , int &ans , int curD , int d )
    {
        if( cur == NULL ) return;
        
        if( curD == d ) ans += cur -> val;
        
        sum ( cur -> left , ans , curD + 1 , d );
        sum( cur -> right , ans , curD + 1 , d );
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        // we can solve in single traversal by level order traversal
        int d = depth( root );
        
        int ans = 0;
        sum( root , ans , 1 , d );
        return ans;
    }
};














