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
    
    TreeNode * helper( TreeNode * cur , vector<TreeNode *> &ans , unordered_set<int> &s )
    {
        if( cur == NULL ) return NULL;
        
        cur -> left = helper( cur -> left , ans , s );
        cur -> right = helper( cur -> right , ans , s );
        
        if( s.find( cur -> val ) != s.end() ) {
            if( cur -> left )
                ans.push_back( cur -> left );
            if( cur -> right )
                ans.push_back( cur -> right );
            
            delete cur;
            return NULL;
        }
        return cur;        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set <int> s;
        
        for( int i = 0 ; i < to_delete.size() ; i++ )
        {
            s.insert( to_delete[i] );
        }
        
        vector< TreeNode *> ans;
        
        if( s.find( root -> val ) == s.end() )
            ans.push_back( root );
        helper( root , ans , s );
        return ans;
    }
};